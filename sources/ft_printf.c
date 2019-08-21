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

int		main(void)
{
	int	len[8];
	int	i = -1;

	len[0] = ft_printf("{%03.d}\n", 0);
 	len[1] = ft_printf("%.4d\n", 424242);
	len[2] = ft_printf("%.4d\n", -424242);
	len[3] = ft_printf("%15.4d\n", 42);
	len[4] = ft_printf("%15.4d\n", 424242);
	len[5] = ft_printf("%8.4d\n", 424242424);
	len[6] = ft_printf("%15.4d\n", -42);
	len[7] = ft_printf("%15.4d\n", -424242);
	while (++i < 8)
		printf("len[%d]: %d\n", i, len[i]);
	return (0);
}
