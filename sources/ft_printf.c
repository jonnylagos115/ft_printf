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

int 	my_vfprintf(const char *fmt, va_list arg)
{
	t_format_s 	fs;

	fs.num_chr = 0;
	while (*fmt)
	{
		while (*fmt == '%')
		{
			fmt++;
			if (!parse_f_specifiers(&fmt, &fs))
			{
				handle_args(&fs, arg);
				print_args(&fs);
			}
		}
		if (*fmt)
		{
			ft_putchar(*fmt);
			fmt++;
			fs.num_chr++;
		}
	}
	return (fs.num_chr);
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
