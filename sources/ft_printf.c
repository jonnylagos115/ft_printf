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
	
	fs.num_args = 0;
	while (*fmt)
	{
		while (*fmt == '%')
		{
			fmt++;
			parse_f_specifiers(&fmt, &fs);
			print_args(&fs, arg);
		}
		if (*fmt)
		{
			ft_putchar(*fmt);
			fmt++;
			fs.num_args++;
		}
	}
	return (fs.num_args);
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

/*int		main(void)
{
	ft_printf("%u %u %u %u %u\n", 1, 100, 999, 42, 999988888);
	ft_printf("a %u b %u c %u d\n", 0, 55555, 100000);
	ft_printf("%u\n", UINT_MAX);
	return (0);
}*/
