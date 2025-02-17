/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <rduport@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:59:12 by rduport           #+#    #+#             */
/*   Updated: 2024/11/28 15:13:08 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_charac(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}
