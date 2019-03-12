/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:14:46 by mabouce           #+#    #+#             */
/*   Updated: 2019/01/28 17:51:03 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_struct *stru)
{
	t_list	*tmp;
	void	*last;
	void	*swap;

	if (!stru->pile_a)
		return ;
	tmp = stru->pile_a;
	if (!tmp->next)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp->data;
	tmp = stru->pile_a;
	while (tmp)
	{
		swap = tmp->data;
		tmp->data = last;
		last = swap;
		tmp = tmp->next;
	}
}

void	ft_rrb(t_struct *stru)
{
	t_list	*tmp;
	void	*last;
	void	*swap;

	if (!stru->pile_b)
		return ;
	tmp = stru->pile_b;
	if (!tmp->next)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp->data;
	tmp = stru->pile_b;
	while (tmp)
	{
		swap = tmp->data;
		tmp->data = last;
		last = swap;
		tmp = tmp->next;
	}
}

void	ft_rrr(t_struct *stru)
{
	ft_rra(stru);
	ft_rrb(stru);
}
