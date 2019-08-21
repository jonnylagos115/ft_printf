/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:44:04 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/16 12:44:06 by jlagos           ###   ########.fr       */
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

void	ft_store_memaddr(void *addr, t_format_s *ret)
{
	char		buf[16];
	int			i;
	int			j;
	uintptr_t 	p;

	p = (uintptr_t)addr;
	i = (sizeof(p) << 3) - 4;
	j = 1;
	ft_memcpy(buf, "0x", 2);
	while ((p && i >= 0) && get_hex_digit((p >> i) & 0xf) == '0')
		i -= 4;
	while (p && i >= 0)
	{
		buf[++j] = get_hex_digit((p >> i) & 0xf);
		i -= 4;
	}
	if (!p)
		buf[++j] = '0';
	buf[j + 1] = '\0';
	ret->args = ft_strdup(buf);
}

void	handle_args(t_format_s *ret, va_list args)
{
	if (IS_SIGNED(ret->format_s))
	{
		ret->s_numarg = get_signed_nbr(args, ret->length_s);
		ret->num_digit = snbr_digits(ret->s_numarg);
		if (ret->precision >= 0)
		{
			if (ret->width_s < ret->num_digit)
				ret->width_s = 0;
			if (ret->precision < ret->num_digit)
				ret->precision = 0;
		}
	}
	else if (IS_UNSIGNED(ret->format_s))
	{
		ret->u_numarg = get_unsigned_nbr(args, ret->length_s);
		ret->num_digit = unbr_digits(ret->u_numarg, ret->format_s);
	}
	else if (ret->format_s == 'c' || ret->format_s == '%')
	{
		if (ret->format_s == 'c')
			ret->c = va_arg(args, int);
		ret->num_digit = 1;
	}
	else
	{
		if (ret->format_s == 'p')
			ft_store_memaddr(va_arg(args, char *), ret);
		else if (ret->format_s == 's')
			ret->args = va_arg(args, char *);
		ret->num_digit = ft_strlen(ret->args);
	}
}
