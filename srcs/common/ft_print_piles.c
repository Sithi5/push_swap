/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:27:57 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 15:31:27 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_data_piles(t_struct *stru)
{
	t_list *tmpa;
	t_list *tmpb;

	tmpa = stru->pile_a;
	tmpb = stru->pile_b;
	while (tmpa || tmpb)
	{
		if (tmpa)
		{
			ft_putstr("\033[32m \t\t\t\t\t\t\t\t\t");
			miniprintf("%i\t\x1b[0m\x1b[33m ||\x1b[0m", tmpa->data);
			tmpa = tmpa->next;
		}
		else
			miniprintf("\t\t\t\t\t\t\t\t\t\t\x1b[33m || \x1b[0m");
		if (tmpb)
		{
			miniprintf("\t\033[31m %i \x1b[0m", tmpb->data);
			tmpb = tmpb->next;
		}
		ft_putchar('\n');
	}
}

void	ft_print_piles(t_struct *stru)
{
	system("clear");
	ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	ft_putstr("\x1b[33m \t\t\t\t\t\t\t\t");
	ft_putstr("===================================\n\x1b[0m");
	ft_putstr("\x1b[33m \t\t\t\t\t\t\t\t\t[A]\t\t[B]\n\x1b[0m");
	ft_print_data_piles(stru);
	ft_putstr("\x1b[33m \t\t\t\t\t\t\t\t");
	ft_putstr("=================================== \n\x1b[0m");
	system("sleep 0.05");
}
