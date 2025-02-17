/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduport <rduport@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:58:54 by rduport           #+#    #+#             */
/*   Updated: 2024/12/10 14:29:32 by rduport          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_param(va_list *args, const char format)
{
	int	total;

	total = 0;
	if (format == 'c')
		total += ft_print_charac(va_arg(*args, int));
	else if (format == 's')
		total += ft_print_string(va_arg(*args, char *));
	else if (format == 'p')
		total += ft_print_pointer((uintptr_t)va_arg(*args, unsigned long long));
	else if (format == 'd' || format == 'i')
		total += ft_print_decimal(va_arg(*args, int));
	else if (format == 'u')
		total += ft_print_unsigned_decimal(va_arg(*args, unsigned int));
	else if (format == 'x')
		total += ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == 'X')
		total += ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		total += ft_print_percent();
	return (total);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total_car;
	va_list	args;

	va_start(args, format);
	total_car = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			total_car += ft_print_param(&args, format[++i]);
		else
			total_car += ft_print_charac(format[i]);
		i++;
	}
	va_end(args);
	return (total_car);
}

/*int	main(int argc, char **argv)
{
	if(argc == 3)
	{
		int i = ft_printf("%c", argv[1][0]);
		int j = printf("%c", argv[1][0]);
		printf("\n");
		ft_printf("return value of ft_printf of '%c' : %d\n",argv[1][0], i);
		printf("return value of printf of '%c' : %d\n", argv[1][0], j);

		printf("\n\n");

		//i = ft_printf("%s", NULL);
		//j = printf("%s", NULL);
		printf("\n");
		ft_printf(" NULL %s NULL ", NULL);
		printf("\n");
		printf(" NULL %s NULL ", NULL);
		printf("\n");
		//ft_printf("return value of ft_printf of '%s' : %d\n",NULL, i);
		//printf("return value of printf of '%s' : %d\n", NULL, j);

		printf("\n\n");

		i = ft_printf(" %p %p ", 0, 0);
		j = printf(" %p %p ", 0, 0);
		printf("\n");
		ft_printf("return value of ft_printf of ' %p %p ' : %d\n", 0, 0, i);
		printf("return value of printf of    ' %p %p ' : %d\n", 0, 0, j);

		printf("\n\n");

		i = ft_printf("%d", atoi(argv[1]));
		j = printf("%d", atoi(argv[1]));
		printf("\n");
		ft_printf("return value of ft_printf of '%d' : %d\n",atoi(argv[1]), i);
		printf("return value of printf of '%d' : %d\n", atoi(argv[1]), j);

		printf("\n\n");

		i = ft_printf("%i", atoi(argv[5]));
		j = printf("%i", atoi(argv[5]));
		printf("\n");
		ft_printf("return value of ft_printf of '%i' : %d\n",atoi(argv[5]), i);
		printf("return value of printf of '%i' : %d\n", atoi(argv[5]), j);

		printf("\n\n");

		i = ft_printf("%u", (unsigned)atoi(argv[6]));
		j = printf("%u", (unsigned)atoi(argv[6]));
		printf("\n");
		ft_printf("return value of ft_printf of '%u' :
		 %d\n",(unsigned)atoi(argv[6]), i);
		printf("return value of printf of '%u' :
		 %d\n", (unsigned)atoi(argv[6]), j);

		printf("\n\n");

		i = ft_printf("%x", atoi(argv[1]));
		j = printf("%x", atoi(argv[1]));
		printf("\n");
		ft_printf("return value of ft_printf of '%x' : %d\n",atoi(argv[1]), i);
		printf("return value of printf of '%x' : %d\n", atoi(argv[1]), j);

		printf("\n\n");

		i = ft_printf("%X", atoi(argv[2]));
		j = printf("%X", atoi(argv[2]));
		printf("\n");
		ft_printf("return value of ft_printf of '%X' : %d\n",atoi(argv[2]), i);
		printf("return value of printf of '%X' : %d\n", atoi(argv[2]), j);

		printf("\n\n");

		i = ft_printf("%%");
		j = printf("%%");
		printf("\n");
		ft_printf("return value of ft_printf of '%%' : %d\n", i);
		printf("return value of printf of '%%' : %d\n", j);

	}
}*/
