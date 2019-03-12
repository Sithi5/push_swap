/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:31:48 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/06 17:01:43 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_struct(t_struct *stru)
{
	stru->pile_a = NULL;
	stru->pile_b = NULL;
	stru->input = NULL;
	stru->flag_visu = 0;
	stru->flag_count_instru = 0;
	stru->flag_light = 0;
}

void	ft_clear_struct(t_struct *stru)
{
	ft_list_clear(&stru->pile_a);
	ft_list_clear(&stru->pile_b);
	ft_list_clear_data(&stru->input);
	free(stru);
}
