/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:50:23 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 18:46:15 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

char	*ft_int(t_stru *stru)
{
	long long	i;
	char		*tmp;

	i = va_arg(stru->va, long long);
	tmp = ft_lltoa(i);
	return (tmp);
}
