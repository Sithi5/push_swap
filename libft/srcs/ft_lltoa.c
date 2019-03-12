/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:38:40 by mabouce           #+#    #+#             */
/*   Updated: 2019/01/23 15:17:13 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_size(long long nb)
{
	int size;

	size = 1;
	while (nb >= 10 || nb <= -10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char			*ft_lltoa(long long n)
{
	char				*dest;
	int					size;
	unsigned long long	nb;

	size = ft_count_size(n);
	if (n < 0)
	{
		nb = -n;
		size++;
	}
	else
		nb = n;
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n < 0)
		dest[0] = '-';
	dest[size] = '\0';
	while (nb >= 10)
	{
		dest[size - 1] = nb % 10 + 48;
		size--;
		nb /= 10;
	}
	dest[size - 1] = nb + 48;
	return (dest);
}
