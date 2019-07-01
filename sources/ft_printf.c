/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:14:24 by jlagos            #+#    #+#             */
/*   Updated: 2019/06/03 12:05:06 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <printf.h>

int 	my_vfprintf(const char *fmt, va_list arg)
{
	t_format_s 	fs;
	int			n;

	n = 0;
	while (*fmt)
	{
		while (*fmt == '%')
		{
			fmt++;
			parse_f_specifiers(&fmt, &fs);
			print_args(&fs, arg, &n);
		}
		if (*fmt)
		{
			ft_putchar(*fmt);
			fmt++;
			n++;
		}
	}
	return (n);
}

int 	ft_printf(const char *restrict format, ...)
{
    va_list args;
	int		done;
	
	va_start(args, format);
	done = my_vfprintf(format, args);
    va_end(args);
	return (done);
}

int		main(void)
{
	ft_printf("%ld%ld\n", 0l, 42l);
	ft_printf("%ld\n", (long)INT_MAX + 1);
	ft_printf("%ld\n", (long)INT_MIN - 1);
	ft_printf("%ld\n", LONG_MAX);
	ft_printf("%ld\n", LONG_MIN);
	ft_printf("%li\n", (long)INT_MAX + 1);
	ft_printf("%li\n", (long)INT_MIN - 1);
	ft_printf("%li\n", LONG_MAX);
	ft_printf("%li\n", LONG_MIN);
	ft_printf("%lu, %lu\n", 0ul, ULONG_MAX);
	ft_printf("%lo, %lo\n", 0ul, ULONG_MAX);
	ft_printf("%lx, %lx\n", 0ul, ULONG_MAX);
	ft_printf("%lX, %lX\n", 0ul, ULONG_MAX);
	return (0);
}
