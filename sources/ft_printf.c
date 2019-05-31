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

#include "../ft_printf.h"
#include <printf.h>

void	ft_puthex(unsigned long num, char convert_case) //print hex of a value from converted base 10
{
	long remainder;

	remainder = num % 16;
	if (num / 16)	//used recursion to print remainders from last to first
		ft_puthex(num / 16, convert_case);
	if (remainder > 9)
	{
		remainder += 87;
		if (convert_case == 'X')
			ft_putchar(ft_toupper(remainder));
		else
			ft_putchar(remainder);
	}
	else
		ft_putchar(remainder + '0');
}

void	ft_putoctal(unsigned long octal)
{
	long remainder;

	remainder = octal % 8;
	if (octal / 8)
		ft_putoctal(octal / 8);
	ft_putchar(remainder + '0');
}

void	ft_putnbr_u(unsigned int n)
{
	if (n > UNSIGNED_INT_MAX)
		n = UNSIGNED_INT_MAX;
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putnbr_l(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == LONG_MIN)
		{
			ft_putchar('9');
			n %= 1000000000000000000;
		}
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_l(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putnbr_ul(unsigned long n)
{
	if (n > 9)
		ft_putnbr_ul(n / 10);
	ft_putchar(n % 10 + '0');
}

void	format_specifier(char **format, va_list args)
{
	while (**format == 'h')
		(*format)++;
	if (**format == 'l')
	{
		(*format)++;
		if (**format == 'l')
			(*format)++;
		if (**format == 'd' || **format == 'i')
			ft_putnbr_l(va_arg(args, long));
		if (**format == 'u')
			ft_putnbr_u(va_arg(args, unsigned int));
		if (**format == 'x' || **format == 'X')
			ft_puthex(va_arg(args, unsigned long), **format);
		if (**format == 'o')
			ft_putoctal(va_arg(args, unsigned long));
	}
	else
	{
		if (**format == 'd' || **format == 'i')
			ft_putnbr(va_arg(args, int));
		if (**format == 'u')
			ft_putnbr_u(va_arg(args, unsigned int));
		if (**format == 'p' || **format == 'x' || **format == 'X')
		{
			if (**format == 'p')
				ft_putstr("0x");
			ft_puthex(va_arg(args, unsigned long), **format);
		}
		if (**format == 'c')
			ft_putchar(va_arg(args, int));
		if (**format == 's')
			ft_putstr(va_arg(args, char *));
		if (**format == 'o')
			ft_putoctal(va_arg(args, unsigned long));
	}
	(*format)++;
}

int 	ft_printf(const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);
 
    while (*format != '\0') 
	{
        if (*format == '%') 
		{
			++format;
			format_specifier((char **)(&format), args);
        }
		ft_putchar(*format);
        ++format;
    }
    va_end(args);
	return (1);
}
