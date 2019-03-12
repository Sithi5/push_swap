/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss_rr_rrr_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:10:33 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/03 18:27:13 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss_print(t_struct *stru)
{
	ft_ss(stru);
	ft_putstr("ss\n");
}

void	ft_rr_print(t_struct *stru)
{
	ft_rr(stru);
	ft_putstr("rr\n");
}

void	ft_rrr_print(t_struct *stru)
{
	ft_rrr(stru);
	ft_putstr("rrr\n");
}
