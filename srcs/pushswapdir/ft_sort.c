/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:09:00 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/06 14:36:27 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort_pill_b(t_struct *stru, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stru->pile_b;
	i = 1;
	if (tmp)
	{
		while (i < size && tmp->next)
		{
			if ((int)tmp->data < (int)tmp->next->data)
				return (0);
			i++;
			tmp = tmp->next;
		}
	}
	return (1);
}

int		ft_is_sort_pill_a(t_struct *stru, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stru->pile_a;
	i = 1;
	if (tmp)
	{
		while (i < size && tmp->next)
		{
			if ((int)tmp->data > (int)tmp->next->data)
				return (0);
			i++;
			tmp = tmp->next;
		}
	}
	return (1);
}
