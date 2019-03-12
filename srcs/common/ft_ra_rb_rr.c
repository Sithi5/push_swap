/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:09:44 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/03 18:13:20 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_struct *stru)
{
	t_list	*tmp;
	void	*first;

	if (!stru->pile_a)
		return ;
	tmp = stru->pile_a;
	first = stru->pile_a->data;
	while (tmp)
	{
		if (!tmp->next)
			tmp->data = first;
		else
			tmp->data = tmp->next->data;
		tmp = tmp->next;
	}
}

void	ft_rb(t_struct *stru)
{
	t_list	*tmp;
	void	*first;

	if (!stru->pile_b)
		return ;
	tmp = stru->pile_b;
	first = stru->pile_b->data;
	while (tmp)
	{
		if (!tmp->next)
			tmp->data = first;
		else
			tmp->data = tmp->next->data;
		tmp = tmp->next;
	}
}

void	ft_rr(t_struct *stru)
{
	ft_rb(stru);
	ft_ra(stru);
}
