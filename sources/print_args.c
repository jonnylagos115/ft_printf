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

void	ft_print_integer(t_format_s *ret, int base)
{
	char		base_digits[16];
	int			converted_nbr[64];
	int			i;

	i = -1;
	if (ret->format_s == 'X')
		ft_strcpy(base_digits, "0123456789ABCDEF");
	else
		ft_strcpy(base_digits, "0123456789abcdef");
	while (ret->u_numarg != 0)
	{
		converted_nbr[++i] = ret->u_numarg % base;
		ret->u_numarg = ret->u_numarg / base;
	}
	if (i < 0)
	{
		write(1, "0", 1);
		ret->num_chr++;
	}
	while (i >= 0)
	{
		write(1, &base_digits[converted_nbr[i--]], 1);
		ret->num_chr++;
	}
}

void	print_signed_nbr(t_format_s *ret, intmax_t n)
{
	if (n < 0)
	{
		if (!ret->no_minus)
			write(1, "-", 1);
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

void		print_float_nbr(t_format_s *ret, double n)
{
	int				num_len;
	int				len;
	intmax_t		some_nbr;
	int				i;

	num_len = snbr_digits((intmax_t)n);
	len = n;
	i = -1;
	print_signed_nbr(ret, (intmax_t)n);
	write(1, ".", 1);
	if (n < 0)
		n *= (double)-1;
	while (++i < 6)
	{
		some_nbr = n * 10;
		ft_putnbr(some_nbr % 10);
		n *= 10;
	}
	ret->num_chr += ret->num_digit - num_len;
}

void		ft_display_str(t_format_s *ret)
{
	int		i;

	if ((ret->format_s == 's' || ret->format_s == 'p') && ret->args)
	{
		if (ret->no_prec != 1)
		{
			i = -1;
			while (ret->args[++i])
			{
				ft_putchar(ret->args[i]);
				ret->num_chr++;
			}
		}
		else if (ret->format_s == 'p') // For cases like "%.0p", "%.p" IF the argument is 0 
		{
			write(1, "0x", 2);
			ret->num_chr += 2;
		}
		if (ret->format_s == 'p' && ret->args[1] != 'x')
		{
			ret->args = ret->args - 2;
			ret->num_chr += 2;
		}
		ft_strdel(&ret->args);
	}
}

void	print_args(t_format_s *ret)
{
	handle_flags(ret);
	if ((ret->width_s + ret->precision) > ret->num_digit)
	{
		handle_w_p(ret); //handles values for min_width & precision
		print_w_p(ret); //where it prints min_width & precision
	}
	else
		print_flags(ret);
	if (ret->format_s == 's' || ret->format_s == 'p')
		ft_display_str(ret);
	if ((IS_SIGNED(ret->format_s)) && ret->no_prec != 1)
		print_signed_nbr(ret, ret->s_numarg);
	if ((IS_UNSIGNED(ret->format_s)) && ret->no_prec != 1)
	{
		if ((ret->format_s == 'x' || ret->format_s == 'X'))
			ft_print_integer(ret, 16);
		else if (ret->format_s == 'o')
			ft_print_integer(ret, 8);
		else
			ft_print_integer(ret, 10);
	}
	/*if (ret->format_s == 'o' && ret->flag_s & SHARP) //precision is ignored for this edge case
		ft_putoctal(ret, ret->u_numarg);*/
	if (ret->format_s == 'c' || ret->format_s == '%')
	{
		if (ret->format_s == '%')
			write(1, "%", 1);
		else
			ft_putchar(ret->c);
		ret->num_chr++;
	}
	if (ret->format_s == 'f')
		print_float_nbr(ret, ret->f_numarg);
	if (ret->width_s > 0)
		print_w_p(ret);
	//printf("ret->num_chr: %d, ret->width_s: %d\n", ret->num_chr, ret->width_s);
}
