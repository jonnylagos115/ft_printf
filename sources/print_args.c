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

intmax_t	get_signed_nbr(va_list args, int length_s)
{
	intmax_t n;

	n = va_arg(args, intmax_t);
	if (!length_s)
		n = (int)n;
	else if (length_s & HH)
		n = (char)n;
	else if (length_s & H)
		n = (short)n;
	else if (length_s & l)
		n = (long)n;
	else if (length_s & ll)
		n = (long long)n; 
	return (n);
}

uintmax_t	get_unsigned_nbr(va_list args, int length_s)
{
	uintmax_t n;

	n = va_arg(args, uintmax_t);
	if (!length_s)
		n = (unsigned int)n;
	else if (length_s & HH)
		n = (unsigned char)n;
	else if (length_s & H)
		n = (unsigned short)n;
	else if (length_s & l)
		n = (unsigned long)n;
	else if (length_s & ll)
		n = (unsigned long long)n; 
	return (n);
}

char	get_hex_digit(int c)
{
	if (c >= 0 && c <= 9)
		return (c + '0');
	else
		return ('a' + c - 10);
}

void	ft_printhex(intmax_t num, char c)
{
	int remainder;

	remainder = num % 16;
	if (num / 16)	//used recursion to print remainders from last to first
		ft_printhex(num / 16, c);
	if (remainder > 9)
	{
		remainder += 87;
		if (c == 'X')
			remainder -= 32;
		ft_putchar(remainder);
	}
	else
		ft_putchar(remainder + '0');
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

void	ft_putoctal(uintmax_t num)
{
	unsigned long		octal;
	unsigned long		i;

	octal = 0;
	i = 1;
	while (num > 0)
	{
		octal = octal + (num % 8) * i;
		i *= 10;
		num /= 8;
	}
}

void		print_signed_nbr(intmax_t n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == INT_MIN)
		{
			write(1, "2", 1);
			n %= 1000000000;
		}
		else if (n == LLONG_MIN)
		{
			write(1, "9", 1);
			n %= 1000000000000000000;
		}
		n *= -1;
	}
	if (n > 9)
		print_signed_nbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int			ft_display_str(char *str)
{
	if (str)
		ft_putstr(str);
	return (ft_strlen(str));
}

void		print_unsigned_nbr(uintmax_t n, char fs)
{
	if (fs == 'x' || fs == 'X')
		ft_printhex(n, fs);
	else if (fs == 'o')
		ft_putoctal(n);
	else
	{
		if (n > 9)
			print_unsigned_nbr(n / 10, fs);
		ft_putchar(n % 10 + '0');
	}
}

void	print_args(t_format_s *ret, va_list args, int *n)
{
	if (ret->format_s == 's')
		*n += ft_display_str(va_arg(args, char *));
	if (ret->format_s == 'c')
		ft_putchar(va_arg(args, int));
	if (IS_SIGNED(ret->format_s))
		print_signed_nbr(get_signed_nbr(args, ret->length_s));
	if (IS_UNSIGNED(ret->format_s))
		print_unsigned_nbr(get_unsigned_nbr(args, ret->length_s), ret->format_s);
	if (ret->format_s == 'p')
	{
		ft_printmem(va_arg(args, void *));
		(*n)++;
	}
	if (ret->format_s == '%')
	{
		ft_putchar('%');
		(*n)++;
	}
}
