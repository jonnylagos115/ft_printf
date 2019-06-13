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
	t_format_s fs;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			parse_f_specifiers(&fmt, &fs);
			print_args(&fs, arg);
		}
		ft_putchar(*fmt);
		fmt++;
	}
	return (1);
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
	ft_printf("111%s333%s555", "222", "444");
	NL;
	ft_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	NL;
	ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	NL;
	return (0);
}
