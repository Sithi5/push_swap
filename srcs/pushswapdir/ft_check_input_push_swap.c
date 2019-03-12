/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:06:36 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/06 16:11:49 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_av_push_swap(t_struct *stru)
{
	int	i;

	i = 1;
	while (stru->split[stru->j][i])
	{
		if (stru->split[stru->j][i] < '0' || stru->split[stru->j][i] > '9')
			ft_error(stru, -2);
		i++;
	}
	stru->lli = ft_atolli(stru->split[stru->j]);
	if (stru->lli > 2147483647 || stru->lli < -2147483648)
		ft_error(stru, -2);
	ft_check_double(stru, stru->lli);
	if (!(ft_list_push_back(&stru->pile_a, (void *)stru->lli)))
		ft_error(stru, -2);
}

void	ft_check_av_and_fill_push_swap(t_struct *stru)
{
	stru->j = 0;
	while (stru->split[stru->j])
	{
		if (stru->split[stru->j][0] < '0' || stru->split[stru->j][0] > '9')
		{
			if (stru->split[stru->j][0] == '+'
					|| stru->split[stru->j][0] == '-')
			{
				if (stru->split[stru->j][1] < '0'
						|| stru->split[stru->j][1] > '9')
					ft_error(stru, -2);
			}
			else
				ft_error(stru, -2);
		}
		ft_push_av_push_swap(stru);
		stru->j++;
	}
}
