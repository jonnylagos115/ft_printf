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
#include <printf.h>
#include <limits.h>

/*void	print_ptr_in_hex(const void *addr, size_t size)
{
	int i;
	int digit;
	int base_10;
	int power;

	i = 0;
	digit = 0;
	base_10 = 0;
	power = ft_strlen((char*)str) - 1;
	ft_putstr("0x");
	while (str[i])
	{
		digit = convert_to_int(str[i], 16);
		if (digit < 0)
		{
			ft_putstr("Invalid\n");
			return (digit);
		}
		base_10 += digit * power_of_ret(str_base, power);
		power--;
		i++;
	}
	return (base_10);
}*/

void	ft_putnbrl(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n == -2147483648)
	{
		ft_putchar('2');
		n %= 1000000000;
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
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
		{
			if (**format == 'd' || **format == 'i')
				ft_putnbr(va_arg(args, long long));
			if (UNSIGNED(**format))
				ft_putnbr(va_arg(args, long long));
		}
		else
		{
			if (**format == 'd' || **format == 'i')
				ft_putnbr(va_arg(args, long));
			if (UNSIGNED(**format))
				ft_putnbr(va_arg(args, long));
		}
	}
	else
	{
		if (**format == 'd' || **format == 'i')
			ft_putchar(va_arg(args, int));
		if (UNSIGNED(**format))
			ft_putchar(va_arg(args, int));	
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

int		main(void)
{
	unsigned short int i;

	i = 10;
	ft_printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
    ft_printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
	return (0);
}

