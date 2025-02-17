/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <rduport@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:59:06 by rduport           #+#    #+#             */
/*   Updated: 2024/11/28 13:59:08 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	special_case(uintptr_t p)
{
	if (p == '0')
	{
		write(1, "0", 1);
		return (1);
	}
	else if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	return (0);
}

int	ft_print_pointer(uintptr_t p)
{
	int		i;
	int		total;
	char	buffer[16];

	total = 0;
	i = special_case(p);
	if (i != 0)
		return (i);
	while (p > 0)
	{
		buffer[i++] = "0123456789abcdef"[p % 16];
		p = p / 16;
	}
	write(1, "0x", 2);
	total += 2;
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		total++;
	}
	return (total);
}
