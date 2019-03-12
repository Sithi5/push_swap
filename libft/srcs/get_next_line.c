/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:59:45 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/10 14:59:23 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

static t_fd	*find_fd_info(const int fd, t_fd **files)
{
	t_fd	*elem;

	elem = *files;
	while (elem != NULL && elem->fd != fd)
		elem = elem->next;
	if (elem == NULL)
	{
		if (!(elem = (t_fd *)malloc(sizeof(*elem))))
			return (NULL);
		elem->fd = fd;
		elem->data = NULL;
		elem->offset = NULL;
		elem->next = *files;
		*files = elem;
	}
	return (elem);
}

static int	clean_fd_info(const int fd, t_fd **files)
{
	t_fd	*prev;
	t_fd	*curr;

	prev = NULL;
	curr = *files;
	while (curr != NULL && curr->fd != fd)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr != NULL)
	{
		if (prev == NULL)
			*files = curr->next;
		else
			prev->next = curr->next;
		ft_strdel(&(curr->data));
		free(curr);
	}
	return (-1);
}

static int	clean_data(t_fd *elem)
{
	char *tmp;

	tmp = elem->data;
	elem->data = ft_strdup(!(elem->offset) ? "" : elem->offset);
	elem->offset = elem->data;
	ft_strdel(&tmp);
	return (elem->data != NULL);
}

static int	read_line_fd(const int fd, t_fd *elem, char **eol)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	size_read;

	if (!clean_data(elem))
		return (-1);
	size_read = 0;
	while (!(*eol) && (size_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size_read] = '\0';
		if (!(elem->data = ft_strdjoin(elem->data, buff)))
			return (-1);
		elem->offset = elem->data;
		if (ft_memchr(buff, '\n', size_read))
			*eol = ft_strchr(elem->data, '\n');
	}
	if (size_read < 0)
		return (-1);
	if (size_read == 0 && (elem->data)[0] == '\0')
		return (0);
	if (size_read == 0 && *elem->data - 1 != '\n')
		return (-3);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd	*files = NULL;
	t_fd		*elem;
	char		*eol;
	int			result;

	if (fd < 0)
		return (-1);
	if (line == NULL)
		return (clean_fd_info(fd, &files));
	if (!(elem = find_fd_info(fd, &files)))
		return (-1);
	eol = NULL;
	if ((!(elem->offset) || !(eol = ft_strchr(elem->offset, '\n')))
			&& (result = read_line_fd(fd, elem, &eol)) <= 0)
	{
		clean_fd_info(fd, &files);
		return (result);
	}
	if (eol != NULL)
		*(eol) = '\0';
	if (!(*line = ft_strdup(elem->offset)))
		return (clean_fd_info(fd, &files));
	elem->offset = !(eol) ? NULL : (eol + 1);
	return (1);
}
