/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:16:04 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/06 16:31:09 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear_data(t_list **begin_list)
{
	t_list *save;

	save = *begin_list;
	while ((*begin_list))
	{
		save = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		ft_memdel(&save->data);
		free(save);
	}
}
