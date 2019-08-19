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

void	ft_printhex(t_format_s *ret, uintmax_t num)
{
	uintmax_t remainder;

	remainder = num % 16;
	if (num / 16)	//used recursion to print remainders from last to first
		ft_printhex(ret, num / 16);
	if (remainder > 9)
	{
		remainder += 87;
		if (ret->format_s == 'X')
			remainder -= 32;
		ft_putchar(remainder);
		ret->num_chr++;
	}
	else
	{
		ft_putchar(remainder + '0');
		ret->num_chr++;
	}
}

void	ft_putoctal(t_format_s *ret, uintmax_t num)
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
	if (num && ret->flag_s & SHARP)
	{
		write(1, "0", 1);
		ret->num_chr++;
	}
	while (n-- > 0)
	{
		octal = (num / p);
		R = num % p;
		num = R;
		p /= 8;
		ft_putnbr(octal);
		ret->num_chr++;
	}
}

void	print_signed_nbr(t_format_s *ret, intmax_t n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (ret->flag_s & ZERO)
			min_field_width(ret);
		if (n == INT_MIN)
		{
			write(1, "2", 1);
			n %= 1000000000;
			ret->num_chr++;
		}
		else if (n == LLONG_MIN)
		{
			write(1, "9", 1);
			n %= 1000000000000000000;
			ret->num_chr++;
		}
		n *= -1;
		ret->num_chr++;
	}
	if (n > 9)
		print_signed_nbr(ret, n / 10);
	ft_putchar(n % 10 + '0');
	ret->num_chr++;
}

void		ft_display_str(t_format_s *ret)
{
	if ((ret->format_s == 's' || ret->format_s == 'p') && ret->args)
	{
		ret->num_chr += ft_strlen(ret->args);
		ft_putstr(ret->args);
	}
	else if (ret->format_s == 'c')
	{
		ret->num_chr++;
		ft_putchar(ret->c);
	}
}

void		print_unsigned_nbr(t_format_s *ret, uintmax_t n)
{
	if (n > 9)
		print_unsigned_nbr(ret, n / 10);
	ret->num_chr++;
	ft_putchar(n % 10 + '0');
}

void	print_args(t_format_s *ret)
{
	print_flags(ret);
	if (ret->format_s == 'c' || ret->format_s == 's' || ret->format_s == 'p')
		ft_display_str(ret);
	if (IS_SIGNED(ret->format_s))
		print_signed_nbr(ret, ret->s_numarg);
	if (IS_UNSIGNED(ret->format_s))
	{
		if (ret->format_s == 'x' || ret->format_s == 'X')
		{
			if (ret->u_numarg && ret->flag_s & SHARP)
			{
				ft_putchar('0');
				ft_putchar(ret->format_s);
				ret->num_chr += 2;
			}
			ft_printhex(ret, ret->u_numarg);
		}
		else if (ret->format_s == 'o')
			ft_putoctal(ret, ret->u_numarg);
		else
			print_unsigned_nbr(ret, ret->u_numarg);
	}
	if (ret->format_s == '%')
	{
		ft_putchar('%');
		ret->num_chr++;
	}
	if (ret->width_s && (ret->flag_s & MINUS))
		min_field_width(ret);
	if (ret->format_s == 'p')
		ft_strdel(&ret->args);
}
