/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:30:28 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/03 16:49:00 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_print(t_list *begin_list)
{
	if (begin_list == NULL)
		return ;
	while (begin_list != NULL)
	{
		ft_putnbr((int)begin_list->data);
		ft_putchar('\n');
		begin_list = begin_list->next;
	}
	ft_putchar('\n');
}
