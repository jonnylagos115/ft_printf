/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:14:24 by jlagos            #+#    #+#             */
/*   Updated: 2019/05/07 16:15:23 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_printf(const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);
 
    while (*format != '\0') 
	{
        if (*format == '%') 
		{
			++format;
			if (*format == 'd' || *format == 'i')
				ft_putnbr(va_arg(args, int));
			else if (*format == 'c')
				ft_putchar(va_arg(args, int));
			else if (*format == 's')
				ft_putstr(va_arg(args, char *));
			++format;
        }
		ft_putchar(*format);
        ++format;
    }
    va_end(args);
	return (1);
}

int		main(int ac, char **ag)
{
	if (ac == 2)
	{
		char	*str;

		str = ag[1];
		ft_printf("%s : %d, my favorite letter is: %c\n", str, 69, 'J');
	}
	return (0);
}

