/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <rduport@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:59:23 by rduport           #+#    #+#             */
/*   Updated: 2024/11/29 14:05:24 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_print_charac(int c);
int		ft_print_string(char *string);
int		ft_print_pointer(uintptr_t p);
int		ft_print_decimal(int c);
int		ft_print_unsigned_decimal(unsigned int nb);
int		ft_print_hex(unsigned int c, char format);
int		ft_print_percent(void);
int		ft_print_param(va_list *args, const char format);
int		ft_printf(const char *format, ...);
void	ft_putchar(int c);

#endif
