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

void    print_args(format_s *ret, va_list args)
{
    if (ret->format_s & S)
    {
        ft_putstr(va_arg(args, char *));
        ret->format_s = ret->format_s & ~S;
    }
    if (ret->format_s & C)
    {
        ft_putchar(va_arg(args, int));
        ret->format_s = ret->format_s & ~C;
    }
}
