/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:37:12 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/03 16:55:36 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_top_elements_pile_a(t_struct *stru)
{
	if ((int)stru->pile_a->data
			== ft_list_max_value(stru->pile_a, 3))
	{
		ft_sa_print(stru);
		ft_pb_print(stru);
		ft_sa_print(stru);
		ft_pa_print(stru);
		ft_sort_two_first_elem_pile_a(stru);
	}
	else if ((int)stru->pile_a->next->data
			== ft_list_max_value(stru->pile_a, 3))
	{
		ft_pb_print(stru);
		ft_sa_print(stru);
		ft_pa_print(stru);
		ft_sort_two_first_elem_pile_a(stru);
	}
	ft_sort_two_first_elem_pile_a(stru);
}

void	ft_sort_three_top_elements_pile_b(t_struct *stru)
{
	if ((int)stru->pile_b->data
			== ft_list_min_value(stru->pile_b, 3))
	{
		ft_sb_print(stru);
		ft_pa_print(stru);
		ft_sb_print(stru);
		ft_pb_print(stru);
		ft_sort_two_first_elem_pile_b(stru);
	}
	else if ((int)stru->pile_b->next->data
			== ft_list_min_value(stru->pile_b, 3))
	{
		ft_pa_print(stru);
		ft_sb_print(stru);
		ft_pb_print(stru);
		ft_sort_two_first_elem_pile_b(stru);
	}
	ft_sort_two_first_elem_pile_b(stru);
}

void	ft_sort_pile_size_three_a(t_struct *stru)
{
	int	minvalue;
	int	maxvalue;

	minvalue = ft_list_min_value(stru->pile_a, 3);
	maxvalue = ft_list_max_value(stru->pile_a, 3);
	if (((int)stru->pile_a->next->data == maxvalue
			&& (int)stru->pile_a->data == minvalue)
				|| ((int)stru->pile_a->next->next->data == maxvalue
				&& (int)stru->pile_a->next->data == minvalue)
				|| ((int)stru->pile_a->data == maxvalue
					&& (int)stru->pile_a->next->next->data == minvalue))
		ft_sa_print(stru);
	if ((int)stru->pile_a->data == maxvalue
			&& (int)stru->pile_a->next->data == minvalue)
		ft_ra_print(stru);
	else if ((int)stru->pile_a->next->data == maxvalue
			&& (int)stru->pile_a->next->next->data == minvalue)
		ft_rra_print(stru);
}

void	ft_sort_pile_size_three_b(t_struct *stru)
{
	ft_sort_two_first_elem_pile_b(stru);
	if ((int)stru->pile_b->next->next->data > (int)stru->pile_b->data)
		ft_rrb_print(stru);
	ft_pa_print(stru);
	ft_sort_two_first_elem_pile_b(stru);
	ft_pa_print(stru);
	ft_pa_print(stru);
}
