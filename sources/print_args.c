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

void	ft_printhex(uintmax_t num, char c, int *nbr_char)
{
	uintmax_t remainder;

	remainder = num % 16;
	if (num / 16)	//used recursion to print remainders from last to first
		ft_printhex(num / 16, c, nbr_char);
	if (remainder > 9)
	{
		remainder += 87;
		if (c == 'X')
			remainder -= 32;
		ft_putchar(remainder);
		(*nbr_char)++;
	}
	else
	{
		ft_putchar(remainder + '0');
		(*nbr_char)++;
	}
}

void	ft_printmem(void *addr, t_format_s *ret, int *nbr_char) //print hex of a value from converted base 10
{
	int			i;
	int			j;
	int			index;
	int			hex_nbr[16];
	uintptr_t 	p;

	p = (uintptr_t)addr;
	i = (sizeof(p) << 3) - 4;
	j = -1;
	index = 0;
	while (i >= 0)
	{
		hex_nbr[++j] = get_hex_digit((p >> i) & 0xf);
		if (!index && hex_nbr[j] > '0')
			index = j;
		i -= 4;
	}
	if (ret->width_s)
		(*nbr_char) += min_field_width(ret, (16 - index) + 2);
	(*nbr_char) += (16 - index) + 2;
	ft_putstr("0x");
	while (index < 16)
		ft_putchar(hex_nbr[index++]);
}

void	ft_putoctal(uintmax_t num, int *nbr_char)
{
	uintmax_t		octal;
	uintmax_t		R;
	uintmax_t 		p;
	int				n;

	octal = 0;
	R = 1;
	p = 1;
	n = 0;
	while (++n <= 21 && ((p * 8) < num))
		p *= 8;
	while (n-- > 0)
	{
		octal = (num / p);
		R = num % p;
		num = R;
		p /= 8;
		ft_putnbr(octal);
		(*nbr_char)++;
	}
}

void	print_signed_nbr(t_format_s *ret, intmax_t n, int *nbr_char)
{
	if (ret->width_s > 0)
		(*nbr_char) += min_field_width(ret, n);
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == INT_MIN)
		{
			write(1, "2", 1);
			n %= 1000000000;
			(*nbr_char)++;
		}
		else if (n == LLONG_MIN)
		{
			write(1, "9", 1);
			n %= 1000000000000000000;
			(*nbr_char)++;
		}
		n *= -1;
		(*nbr_char)++;
	}
	if (ret->format_s != 'c')
	{
		if (n > 9)
			print_signed_nbr(ret, n / 10, nbr_char);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n);
	(*nbr_char)++;
}

int			ft_display_str(char *str)
{
	int len;

	if (str)
	{
		len = ft_strlen(str);
		ft_putstr(str);
	}
	else
	{
		len = 6;
		ft_putstr("(null)");
	}
	return (len);
}

void		print_unsigned_nbr(uintmax_t n, int *nbr_char)
{
	if (n > 9)
		print_unsigned_nbr(n / 10, nbr_char);
	(*nbr_char)++;
	ft_putchar(n % 10 + '0');
}

void	print_args(t_format_s *ret, va_list args, int *n)
{
	if (ret->format_s == 's')
		*n += ft_display_str(va_arg(args, char *));
	if (IS_SIGNED(ret->format_s))
		print_signed_nbr(ret, get_signed_nbr(args, ret->length_s), n);
	if (IS_UNSIGNED(ret->format_s))
	{
		if (ret->format_s == 'x' || ret->format_s == 'X')
			ft_printhex(get_unsigned_nbr(args, ret->length_s), ret->format_s, n);
		else if (ret->format_s == 'o')
			ft_putoctal(get_unsigned_nbr(args, ret->length_s), n);
		else
			print_unsigned_nbr(get_unsigned_nbr(args, ret->length_s), n);
	}
	if (ret->format_s == 'p')
		ft_printmem(va_arg(args, void *), ret, n);
	if (ret->format_s == '%')
	{
		ft_putchar('%');
		(*n)++;
	}
}
