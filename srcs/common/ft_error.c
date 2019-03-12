/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:14:48 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/07 16:25:35 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_struct *stru, int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == -1)
		ft_clear_struct(stru);
	if (error == -2)
	{
		ft_strtabdel(&stru->split);
		ft_clear_struct(stru);
	}
	if (error == -3)
	{
		ft_strdel(&(stru->line));
		ft_clear_struct(stru);
	}
	exit(0);
}
