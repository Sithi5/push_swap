/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:16:27 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 18:56:14 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPRINTF_H
# define MINIPRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct				s_stru
{
	int						buff;
	int						i;
	int						j;
	int						k;

	char					*format;
	char					*tmp;
	char					*output;
	char					*conv;
	va_list					va;
}							t_stru;

int							miniprintf(const char *format, ...);
int							ft_is_conv(char c, t_stru *stru);

char						*ft_char(t_stru *stru);
char						*ft_string(t_stru *stru);
char						*ft_ptr(t_stru *stru);
char						*ft_int(t_stru *stru);
char						*ft_fill_conv(t_stru *stru);
char						*ft_fill_text(t_stru *stru);

void						ft_error_miniprintf(t_stru *stru, int error);
void						ft_read_format(t_stru *stru);

#endif
