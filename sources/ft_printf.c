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
	ft_printf("%lld%lld\n", 0ll, 42ll);
	ft_printf("%lld\n", LLONG_MAX);
	ft_printf("%lld\n", LLONG_MIN);
	ft_printf("%lli%lli\n", 0ll, 42ll);
	ft_printf("%lli\n", LLONG_MAX);
	ft_printf("%lli\n", LLONG_MIN);
	ft_printf("%llu, %llu\n", 0llu, ULLONG_MAX);
	ft_printf("%llo, %llo\n", 0llu, ULLONG_MAX);
	ft_printf("%llx, %llx\n", 0llu, ULLONG_MAX);
	ft_printf("%llX, %llX\n", 0llu, ULLONG_MAX);
	return (0);
}
