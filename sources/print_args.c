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

void		print_bits(unsigned char octet)
{
	int 			i;
	unsigned char 	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

char	get_hex_digit(int c)
{
	if (c >= 0 && c <= 9)
		return (c + '0');
	else
		return ('a' + c - 10);
}

void	ft_printmem(void *addr) //print hex of a value from converted base 10
{
	int			i;
	int			flag;
	int			hex_digit;
	uintptr_t 	p;

	p = (uintptr_t)addr;
	i = (sizeof(p) << 3) - 4;
	flag = 0;
	ft_putstr("0x");
	while (i >= 0)
	{
		hex_digit = get_hex_digit((p >> i) & 0xf);
		if (hex_digit != '0')
			flag = 1;
		if (flag)
			ft_putchar(hex_digit);
		i -= 4;
	}
	if (!flag)
		ft_putchar('0');
}

void	print_args(t_format_s *ret, va_list args)
{
	if (ret->format_s == 's')
		ft_putstr(va_arg(args, char *));
	if (ret->format_s == 'c')
		ft_putchar(va_arg(args, int));
	if (ret->format_s == 'd' || ret->format_s == 'i')
		ft_putnbr(va_arg(args, int));
	if (ret->format_s == 'p')
		ft_printmem(va_arg(args, void *));
	if (ret->format_s == '%')
		ft_putchar('%');
}
