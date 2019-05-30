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
	long min_nbr = -(long)(((unsigned long)~0 >> 1) -1);
	if (n < 0)
	{
		ft_putchar('-');
		printf("%ld\n", min_nbr);
		if (n == min_nbr)
		{
			printf("helo\n");
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
		if (UNSIGNED(**format))
			ft_putnbr_ul(va_arg(args, unsigned long));
	}
	else
	{
		if (**format == 'd' || **format == 'i')
			ft_putnbr(va_arg(args, int));
		if (UNSIGNED(**format))
			ft_putnbr_u(va_arg(args, unsigned int));	
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
	ft_printf("Minimum Signed Char %d\n", -(char)((unsigned char) ~0 >> 1) - 1);
    ft_printf("Maximum Signed Char %d\n", (char) ((unsigned char) ~0 >> 1));

    ft_printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    ft_printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

    ft_printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    ft_printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

    ft_printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    ft_printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));

    /* Unsigned Maximum Values */

    ft_printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
    ft_printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
    ft_printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
    ft_printf("Maximum Unsigned Long %lu\n",(unsigned long)~0);

	return (0);
}

