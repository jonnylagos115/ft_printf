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
	int	len[3];
	int	i = -1;

	len[0] = ft_printf("{%-10d}\n", 42);
 	len[1] = ft_printf("{%-4d}\n", 10000);
	len[2] = ft_printf("{%-30d}\n", 10000);
	while (++i < 3)
		printf("len[%d]: %d\n", i, len[i]);
	return (0);
}
