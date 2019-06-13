/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:34:20 by jlagos            #+#    #+#             */
/*   Updated: 2019/06/03 15:34:22 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_args(t_format_s *ret, va_list args)
{
	if (ret->format_s == 's')
	{
		ft_putstr(va_arg(args, char *));
		ft_putstr("in here\n");
	}
	if (ret->format_s == 'c')
		ft_putchar(va_arg(args, int));
	if (ret->format_s == 'd' || ret->format_s == 'i')
		ft_putchar(va_arg(args, int));
}
