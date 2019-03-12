/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:55:16 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/07 16:27:18 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_read_input(t_struct *stru)
{
	stru->i = 1;
	while (stru->i < stru->ac)
	{
		if (!(stru->split = ft_strsplit(stru->av[stru->i], ' ')))
			return (-1);
		if (!(ft_check_av_and_fill(stru)))
			return (-2);
		ft_strtabdel(&(stru->split));
		stru->i++;
	}
	while ((stru->ret = get_next_line(0, &stru->line)))
	{
		if (stru->ret == -3)
			return (-1);
		if (!(ft_check_line(stru)))
			return (-3);
		if (!(ft_list_push_back(&stru->input, ft_strdupd(stru->line))))
			return (-3);
	}
	return (1);
}

void	ft_is_sort(t_struct *stru)
{
	t_list *tmp;

	tmp = stru->pile_a;
	if (stru->pile_b)
	{
		ft_putstr("KO\n");
		return ;
	}
	else if (tmp)
	{
		while (tmp->next)
		{
			if ((int)tmp->data >= (int)tmp->next->data)
			{
				ft_putstr("KO\n");
				return ;
			}
			tmp = tmp->next;
		}
	}
	ft_putstr("OK\n");
}

int		main(int ac, char **av)
{
	t_struct	*stru;
	int			ret;

	if (ac < 2)
		return (0);
	if (!(stru = (t_struct *)malloc(sizeof(t_struct))))
		ft_error(stru, 0);
	stru->av = av;
	stru->ac = ac;
	ft_set_struct(stru);
	if (ac < 3 && ft_check_flags(av[1], stru) == 1)
	{
		ft_clear_struct(stru);
		return (0);
	}
	if ((ret = ft_read_input(stru)) < 0)
		ft_error(stru, ret);
	ft_apply_instru(stru);
	ft_is_sort(stru);
	ft_clear_struct(stru);
	return (0);
}
