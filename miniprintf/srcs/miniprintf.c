/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:57:45 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/10 14:24:03 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

int		ft_is_conv(char c, t_stru *stru)
{
	int	i;

	i = 0;
	while (stru->conv[i])
	{
		if (c == stru->conv[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_read_format(t_stru *stru)
{
	stru->i = -1;
	stru->j = 0;
	if (!(stru->output = ft_strnew(0)))
		ft_error_miniprintf(stru, -2);
	while (stru->format[++stru->i])
	{
		if (stru->format[stru->i] == '%')
		{
			if (!(stru->output = ft_strdjoind(stru->output
							, ft_fill_text(stru))))
				ft_error_miniprintf(stru, -3);
			while (stru->format[stru->i]
					&& ft_is_conv(stru->format[stru->i], stru) != 1)
				stru->i++;
			if (!(stru->output = ft_strdjoind(stru->output
							, ft_fill_conv(stru))))
				ft_error_miniprintf(stru, -3);
			stru->i++;
			stru->j = stru->i;
		}
	}
	if (!(stru->output = ft_strdjoind(stru->output, ft_fill_text(stru))))
		ft_error_miniprintf(stru, -3);
}

void	ft_set_conv(t_stru *stru)
{
	stru->conv = "csdi";
}

int		miniprintf(const char *format, ...)
{
	t_stru		*stru;

	if (!(stru = (t_stru *)malloc(sizeof(t_stru))))
		ft_error_miniprintf(stru, 0);
	ft_set_conv(stru);
	va_start(stru->va, format);
	if (!(stru->format = ft_strdup((char *)format)))
		ft_error_miniprintf(stru, -1);
	ft_read_format(stru);
	ft_putstr(stru->output);
	ft_strdel(&(stru->format));
	ft_strdel(&(stru->output));
	free(stru);
	va_end(stru->va);
	return (0);
}
