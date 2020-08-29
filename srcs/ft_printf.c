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

#include "../includes/ft_printf.h"

int		my_vfprintf(const char *fmt, va_list arg)
{
	t_fsptr	fs_ptr;
	int		num_dchr;

	fs_ptr = NULL;
	num_dchr = 0;
	while (*fmt)
	{
		while (*fmt == '%' && fmt++)
		{
			fs_ptr = create_formatspecifer_obj();
			if (!parse_f_specifiers(&fmt, fs_ptr))
			{
				handle_ag(fs_ptr, arg);
				num_dchr += print_args(fs_ptr);
			}
			destroy_formatspecifer_obj(&fs_ptr);
		}
		if (*fmt)
		{
			ft_putchar(*fmt);
			fmt++;
			num_dchr++;
		}
	}
	return (num_dchr);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list args;
	int		done;

	va_start(args, format);
	done = my_vfprintf(format, args);
	va_end(args);
	return (done);
}
