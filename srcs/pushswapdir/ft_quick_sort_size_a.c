/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_size_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:55:43 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 18:41:22 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_quick_sort_push_to_b_or_rotate_a(t_struct *stru, int median)
{
	if ((int)stru->pile_a->data <= median)
	{
		ft_pb_print(stru);
		return (1);
	}
	else
		ft_ra_print(stru);
	return (0);
}

void	ft_quick_sort_push_to_b(t_struct *stru
		, int sizetosort, t_list **sizepile)
{
	int		i;
	int		j;
	int		median;

	while (sizetosort > 3)
	{
		stru->i = sizetosort;
		median = ft_median_of_pile(stru->pile_a, sizetosort);
		i = 0;
		j = 0;
		while (stru->i-- > 0)
		{
			if (ft_quick_sort_push_to_b_or_rotate_a(stru, median) == 1)
			{
				sizetosort--;
				i++;
			}
			else
				j++;
		}
		while (j-- > 0)
			ft_rra_print(stru);
		if (!(ft_list_push_front_int(sizepile, i)))
			ft_error(stru, -2);
	}
}

void	ft_quick_sort_size_a(t_struct *stru, int sizetosort)
{
	t_list	*sizepile;
	t_list	*freelist;

	sizepile = NULL;
	ft_quick_sort_push_to_b(stru, sizetosort, &sizepile);
	freelist = sizepile;
	if (ft_list_size(stru->pile_a) > 1)
	{
		if (ft_list_size(stru->pile_a) > 2)
			ft_sort_three_top_elements_pile_a(stru);
		ft_sort_two_first_elem_pile_a(stru);
	}
	ft_quick_sort_refill_a(stru, sizepile);
	ft_list_clear(&freelist);
}

void	ft_quick_sort_refill_a(t_struct *stru, t_list *sizepile)
{
	int	i;

	while (sizepile)
	{
		i = sizepile->i;
		if (i <= 3)
		{
			while (i-- > 0 && ft_list_size(stru->pile_b))
				ft_pa_print(stru);
			if (sizepile->i == 2)
				ft_sort_two_first_elem_pile_a(stru);
			else if (sizepile->i == 3)
				ft_sort_three_top_elements_pile_a(stru);
		}
		else
		{
			i = sizepile->i;
			ft_quick_sort_size_b(stru, sizepile->i);
			while (i-- > 0)
				ft_pa_print(stru);
		}
		sizepile = sizepile->next;
	}
}
