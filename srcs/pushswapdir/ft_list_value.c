/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:29:54 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/06 14:32:53 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_list_max_value(t_list *list, int size)
{
	int i;

	i = (int)list->data;
	while (size > 0)
	{
		if ((int)list->data > i)
			i = (int)list->data;
		list = list->next;
		size--;
	}
	return (i);
}

int		ft_list_min_value(t_list *list, int size)
{
	int i;

	i = (int)list->data;
	while (size > 0)
	{
		if ((int)list->data < i)
			i = (int)list->data;
		list = list->next;
		size--;
	}
	return (i);
}

int		ft_median_of_pile(t_list *list, int size)
{
	t_list	*explore;
	t_list	*elem;
	int		median;
	int		i[2];
	int		cpysize;

	elem = list;
	i[1] = size;
	median = 0;
	while (i[1]--)
	{
		i[0] = 0;
		explore = list;
		cpysize = size;
		while (cpysize--)
		{
			if ((int)explore->data < (int)elem->data)
				i[0]++;
			explore = explore->next;
		}
		if (i[0] == size / 2)
			median = (int)elem->data;
		elem = elem->next;
	}
	return (median);
}

int		ft_median_of_pile_three(t_list *list, int size)
{
	t_list	*explore;
	t_list	*elem;
	int		median;
	int		i[2];
	int		cpysize;

	elem = list;
	i[1] = size;
	while (i[1]--)
	{
		i[0] = 0;
		explore = list;
		cpysize = size;
		while (cpysize--)
		{
			if ((int)explore->data < (int)elem->data)
				i[0]++;
			explore = explore->next;
		}
		if (i[0] == 3)
			median = (int)elem->data;
		elem = elem->next;
	}
	return (median);
}
