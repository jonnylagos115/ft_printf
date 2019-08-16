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
	int			i;
	int			j;
	uintptr_t 	p;

	p = (uintptr_t)addr;
	i = (sizeof(p) << 3) - 4;
	j = -1;
	if (p == 0)
		ret->args = NULL;
	else
		ret->args = ft_strnew(16);
	while (p && i >= 0)
	{
		ret->args[++j] = get_hex_digit((p >> i) & 0xf);
		i -= 4;
	}
}

void	handle_args(t_format_s *ret, va_list args)
{
	if (IS_SIGNED(ret->format_s))
		ret->s_numarg = get_signed_nbr(args, ret->length_s);
	else if (IS_UNSIGNED(ret->format_s))
		ret->u_numarg = get_unsigned_nbr(args, ret->length_s);
	else if (ret->format_s == 'p')
		ft_store_memaddr(va_arg(args, char *), ret);
	else
	{
		if (ret->format_s == 's')
			ret->args = va_arg(args, char *);
		else if (ret->format_s == 'c')
			ret->c = va_arg(args, int);
	}
}
