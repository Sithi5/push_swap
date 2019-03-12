/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_pa_pb_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:45:28 by mabouce           #+#    #+#             */
/*   Updated: 2019/02/16 18:01:27 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_print(t_struct *stru)
{
	ft_sa(stru);
	ft_putstr("sa\n");
}

void	ft_sb_print(t_struct *stru)
{
	ft_sb(stru);
	ft_putstr("sb\n");
}

void	ft_pa_print(t_struct *stru)
{
	ft_pa(stru);
	ft_putstr("pa\n");
}

void	ft_pb_print(t_struct *stru)
{
	ft_pb(stru);
	ft_putstr("pb\n");
}
