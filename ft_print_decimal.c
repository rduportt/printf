/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <rduport@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:58:49 by rduport           #+#    #+#             */
/*   Updated: 2024/11/28 13:58:50 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	c_is_negative(long *nb)
{
	if (*nb < 0)
	{
		*nb = - (*nb);
		write(1, "-", 1);
		return (1);
	}
	return (0);
}

int	ft_print_decimal(int c)
{
	long	nb;
	int		i;
	int		total;
	int		tab[11];

	i = 0;
	total = 0;
	nb = c;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (c_is_negative(&nb) == 1)
		total++;
	while (nb > 0)
	{
		tab[i] = nb % 10;
		nb /= 10;
		i++;
	}
	total += i;
	while (i > 0)
		ft_putchar(tab[--i] + '0');
	return (total);
}

int	ft_print_unsigned_decimal(unsigned int nb)
{
	int	i;
	int	total;
	int	tab[11];

	i = 0;
	total = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nb > 0)
	{
		tab[i] = nb % 10;
		nb /= 10;
		i++;
	}
	total += i;
	while (i > 0)
		ft_putchar(tab[--i] + '0');
	return (total);
}
