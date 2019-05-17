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

void	*len_specifier(void	*format)
{
	if (*format == 'hh')
	{

	}
	else if (*format == 'h')
	{}
	else if (*format == 'l')
	{}
	else if (*format == 'll')
	{}

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
			len_specifier((void *)format); //return length specifier to cast before printing argument if there is one
			if (*format == 'd' || *format == 'i')
				ft_putnbr(va_arg(args, int));
			else if (*format == 'c')
				ft_putchar(va_arg(args, int));
			else if (*format == 's')
				ft_putstr(va_arg(args, char *));
			else if (*format == '')
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
		Test	yo;

		str = ag[1];
		yo.hi = 152;
		yo.hat = ft_strnew(2);
		yo.hat[0] = 'h';
		yo.hat[1] = 'i';
		ft_printf("%s : %d, my favorite letter is: %c\n", str, 69, 'J');
		printf("address of yo.hi = %p\n", (void *)(&yo.hi));
		printf("address of yo.hat = %p\n", (void *)(&yo.hat));
		printf("number of bytes of yo.hi list = %lu\n", sizeof(yo.hi));
		printf("number of bytes of yo.hat list = %lu\n", sizeof(yo.hat));
		printf("number of bytes of str = %lu\n", sizeof(&str));
		printf("number of bytes of yo list = %lu\n", sizeof(yo));
	}
	return (0);
}

