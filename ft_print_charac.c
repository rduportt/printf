/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_charac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <rduport@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:58:42 by rduport           #+#    #+#             */
/*   Updated: 2024/11/28 13:58:44 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *string)
{
	int	i;

	i = 0;
	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (string[i])
		write(1, &string[i++], 1);
	return (i);
}
