/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:19:41 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/06 16:10:01 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_av_push_swap(t_struct *stru)
{
	stru->i = 1;
	while (stru->i < stru->ac)
	{
		if (!(stru->split = ft_strsplit(stru->av[stru->i], ' ')))
			ft_error(stru, -1);
		ft_check_av_and_fill_push_swap(stru);
		ft_strtabdel(&stru->split);
		stru->i++;
	}
}

int		main(int ac, char **av)
{
	t_struct	*stru;

	if (ac < 2)
		return (0);
	if (!(stru = (t_struct *)malloc(sizeof(t_struct))))
		ft_error(stru, 0);
	stru->av = av;
	stru->ac = ac;
	ft_set_struct(stru);
	ft_check_av_push_swap(stru);
	if (ft_is_sort_pill_a(stru, ft_list_size(stru->pile_a)))
	{
		ft_clear_struct(stru);
		return (0);
	}
	ft_quick_sort(stru);
	ft_clear_struct(stru);
	return (0);
}
