/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:47:22 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/10 14:24:08 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_error_miniprintf(t_stru *stru, int error)
{
	ft_putstr("\nAn error occured.\n");
	if (error == -1)
		free(stru);
	if (error == -2)
	{
		ft_strdel(&(stru->format));
		free(stru);
	}
	if (error == -3)
	{
		ft_strdel(&(stru->format));
		ft_strdel(&(stru->output));
		free(stru);
	}
	exit(0);
}
