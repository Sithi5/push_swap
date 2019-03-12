/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss_pa_pb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:40:09 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 18:40:21 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_struct *stru)
{
	void *swap;

	if (!stru->pile_a || !stru->pile_a->next)
		return ;
	swap = stru->pile_a->data;
	stru->pile_a->data = stru->pile_a->next->data;
	stru->pile_a->next->data = swap;
}

void	ft_sb(t_struct *stru)
{
	void *swap;

	if (!stru->pile_b || !stru->pile_b->next)
		return ;
	swap = stru->pile_b->data;
	stru->pile_b->data = stru->pile_b->next->data;
	stru->pile_b->next->data = swap;
}

void	ft_ss(t_struct *stru)
{
	ft_sa(stru);
	ft_sb(stru);
}

void	ft_pa(t_struct *stru)
{
	t_list *tmp;

	if (!stru->pile_b)
		return ;
	if (!(ft_list_push_front(&stru->pile_a, ft_unstack(stru->pile_b))))
		ft_error(stru, -2);
	if (stru->pile_b->next)
	{
		tmp = stru->pile_b;
		stru->pile_b = stru->pile_b->next;
		free(tmp);
	}
	else
	{
		free(stru->pile_b);
		stru->pile_b = NULL;
	}
}

void	ft_pb(t_struct *stru)
{
	t_list *tmp;

	if (!stru->pile_a)
		return ;
	if (!(ft_list_push_front(&stru->pile_b, ft_unstack(stru->pile_a))))
		ft_error(stru, -2);
	if (stru->pile_a->next)
	{
		tmp = stru->pile_a;
		stru->pile_a = stru->pile_a->next;
		free(tmp);
	}
	else
	{
		free(stru->pile_a);
		stru->pile_a = NULL;
	}
}
