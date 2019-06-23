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
		}
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
	ft_printf("%%\n");
	//NL;
	ft_printf("aa%%bb\n");
	//NL;
	ft_printf("%%%%%%%%%%\n");
	//NL;
	ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	//NL;
	ft_printf("%\n");
	//NL;
	ft_printf("% Zoooo\n");
	//NL;
	ft_printf("{%}\n");
	//NL;
	ft_printf("{% %}\n");

	return (0);
}
