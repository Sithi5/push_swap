/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_instru.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:23:27 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/06 15:54:04 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_db_instru(t_struct *stru)
{
	stru->tab[0] = ft_sa;
	stru->tab[1] = ft_sb;
	stru->tab[2] = ft_ss;
	stru->tab[3] = ft_pa;
	stru->tab[4] = ft_pb;
	stru->tab[5] = ft_ra;
	stru->tab[6] = ft_rb;
	stru->tab[7] = ft_rr;
	stru->tab[8] = ft_rra;
	stru->tab[9] = ft_rrb;
	stru->tab[10] = ft_rrr;
}

void	ft_apply_flag_instru(t_struct *stru)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = stru->input;
	if (stru->flag_count_instru == 1 && stru->flag_light != 1)
	{
		system("clear");
		ft_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		ft_putstr("\n\n\n\n\t\t\t\t\t\t\t===================================");
		ft_putstr("=========\n\t\t\t\t\t\t\tNombre instructions = ");
		miniprintf("%i\n", ft_list_size(stru->input));
		while (tmp)
		{
			ft_putstr("\t\t\t\t\t\t\t");
			miniprintf("Instruction no: %i = %s\n", i, (char *)tmp->data);
			tmp = tmp->next;
			i++;
		}
		ft_putstr("\t\t\t\t\t\t\t");
		ft_putstr("============================================\n");
		system("sleep 1");
	}
	else if (stru->flag_count_instru == 1 && stru->flag_light == 1)
		miniprintf("Nombre instructions = %i\n", ft_list_size(stru->input));
}

void	ft_apply_flag(t_struct *stru)
{
	ft_apply_flag_instru(stru);
	if (stru->flag_visu == 1)
		ft_print_piles(stru);
}

void	ft_apply_instru(t_struct *stru)
{
	t_list	*tmp;

	ft_set_db_instru(stru);
	tmp = stru->input;
	ft_apply_flag(stru);
	while (tmp)
	{
		stru->i = 0;
		while (stru->i < 11)
		{
			if (ft_strequ((char *)tmp->data, stru->db[stru->i]))
				stru->tab[stru->i](stru);
			stru->i++;
		}
		if (stru->flag_visu == 1)
			ft_print_piles(stru);
		tmp = tmp->next;
	}
}
