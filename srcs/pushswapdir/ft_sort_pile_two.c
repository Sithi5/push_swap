/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_pile_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:58:10 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/03 16:35:47 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two_first_elem_pile_a(t_struct *stru)
{
	if ((int)stru->pile_a->data > (int)stru->pile_a->next->data)
		ft_sa_print(stru);
}

void	ft_sort_two_first_elem_pile_b(t_struct *stru)
{
	if ((int)stru->pile_b->data < (int)stru->pile_b->next->data)
		ft_sb_print(stru);
}
