/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:09:00 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 18:42:44 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_sort(t_struct *stru)
{
	if (ft_list_size(stru->pile_a) == 3)
		ft_sort_pile_size_three_a(stru);
	else if (ft_list_size(stru->pile_a) == 2)
		ft_sort_two_first_elem_pile_a(stru);
	if (ft_list_size(stru->pile_b) == 3)
		ft_sort_pile_size_three_b(stru);
}

int		ft_quick_sort_push_or_rotate_first(t_struct *stru, int median)
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

void	ft_quick_sort(t_struct *stru)
{
	int		median;
	int		i;
	t_list	*sizepile;
	t_list	*freelist;

	sizepile = NULL;
	while (ft_list_size(stru->pile_a) > 3)
	{
		stru->i = ft_list_size(stru->pile_a);
		median = ft_median_of_pile(stru->pile_a, stru->i);
		i = 0;
		while (stru->i-- > -1)
		{
			i += ft_quick_sort_push_or_rotate_first(stru, median);
		}
		if (!(ft_list_push_front_int(&sizepile, i)))
			ft_error(stru, -2);
	}
	freelist = sizepile;
	ft_first_sort(stru);
	ft_quick_sort_refill_a(stru, sizepile);
	ft_list_clear(&freelist);
}
