/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:08:57 by jlagos            #+#    #+#             */
/*   Updated: 2019/09/17 16:09:04 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	get_signed_nbr(t_format_s *ret, va_list args, int length_s)
{
	intmax_t n;

	n = va_arg(args, intmax_t);
	if (!length_s)
		n = (int)n;
	else if (length_s & z)
		n = (ssize_t)n;
	else if (length_s & j)
		n = (intmax_t)n;
	else if (length_s & l)
		n = (long)n;
	else if (length_s & ll)
		n = (long long)n; 
	else if (length_s & HH)
		n = (char)n;
	else if (length_s & H)
		n = (short)n;
	ret->s_numarg = n;
	ret->num_digit = snbr_digits(ret->s_numarg);
}

void	get_unsigned_nbr(t_format_s *ret, va_list args, int length_s)
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
	else if (length_s & z)
		n = (size_t)n;
	else if (length_s & j)
		n = (uintmax_t)n;
	ret->u_numarg = n;
	ret->num_digit = unbr_digits(ret->u_numarg, ret->format_s);
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
	ret->num_digit = ft_strlen(ret->args);
}

void	handle_ag(t_format_s *ret, va_list args)
{
	char	*tmp;

	if (IS_SIGNED(ret->format_s))
		get_signed_nbr(ret, args, ret->length_s);
	else if (IS_UNSIGNED(ret->format_s))
		get_unsigned_nbr(ret, args, ret->length_s);
	else if (ret->format_s == 'c' || ret->format_s == '%')
	{
		if (ret->format_s == 'c')
			ret->c = va_arg(args, int);
		ret->num_digit = 1;
	}
	else if (ret->format_s == 'f')
	{
		ret->f_numarg = va_arg(args, double);
		ret->num_digit = snbr_digits(ret->f_numarg);
		ret->num_digit += 7;
		if (ret->length_s == 'L')
			ret->f_numarg = (long double)ret->f_numarg;
	}
	else
	{
		if (ret->format_s == 'p')
			ft_store_memaddr(va_arg(args, char *), ret);
		else if (ret->format_s == 's' && (tmp = va_arg(args, char *)))
		{
			ret->num_digit = ft_strlen(tmp);
			if (ret->precision > 0 && ret->precision <= ret->num_digit)
			{
				ret->num_digit = ret->precision;
				ret->args = ft_strsub(tmp, 0, (size_t)ret->precision);
			}
			else
			{
				ret->args = ft_strdup(tmp);
				ret->num_digit = ft_strlen(ret->args);
			}
		}
		if (ret->format_s == 's' && !tmp && ret->precision != -2)
		{
			ret->num_digit = 6;
			if (ret->precision > 0 && ret->precision <= ret->num_digit)
			{
				ret->num_digit = ret->precision;
				ret->args = ft_strsub("(null)", 0, (size_t)ret->precision);
			}
			else
				ret->args = ft_strdup("(null)");
		}
	}
}