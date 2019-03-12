/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:56:57 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 16:39:45 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_double(t_struct *stru, long long lli)
{
	t_list *pile_tmp;

	pile_tmp = stru->pile_a;
	while (pile_tmp)
	{
		if ((int)pile_tmp->data == (int)lli)
		{
			ft_error(stru, -2);
		}
		pile_tmp = pile_tmp->next;
	}
}
