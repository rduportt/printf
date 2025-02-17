/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <rduport@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:59:00 by rduport           #+#    #+#             */
/*   Updated: 2024/11/28 13:59:02 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hex(unsigned int c)
{
	int	i;

	i = 0;
	while (c != 0)
	{
		i++;
		c = c / 16;
	}
	return (i);
}

int	ft_print_hex(unsigned int c, char format)
{
	if (c == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (c >= 16)
	{
		ft_print_hex(c / 16, format);
		ft_print_hex(c % 16, format);
	}
	else
	{
		if (c <= 9)
			ft_putchar(c + '0');
		else
		{
			if (format == 'x')
				ft_putchar(c - 10 + 'a');
			if (format == 'X')
				ft_putchar(c - 10 + 'A');
		}
	}
	return (len_hex(c));
}
