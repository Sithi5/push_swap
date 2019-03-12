/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb_rra_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:41:49 by mabouce           #+#    #+#             */
/*   Updated: 2019/02/16 17:45:04 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb_print(t_struct *stru)
{
	ft_rrb(stru);
	ft_putstr("rrb\n");
}

void	ft_rra_print(t_struct *stru)
{
	ft_rra(stru);
	ft_putstr("rra\n");
}

void	ft_rb_print(t_struct *stru)
{
	ft_rb(stru);
	ft_putstr("rb\n");
}

void	ft_ra_print(t_struct *stru)
{
	ft_ra(stru);
	ft_putstr("ra\n");
}
