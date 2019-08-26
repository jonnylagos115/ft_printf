/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:53:10 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/12 16:53:11 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		get_hex_len(uintmax_t num)
{
	int		i;
	int		len;

	i = (sizeof(num) << 3) - 4;
	len = 0;
	while ((num && i >= 0) && get_hex_digit((num >> i) & 0xf) == '0')
		i -= 4;
	while (num && i >= 0)
	{
		len++;
		i -= 4;
	}
	return (len);
}

int		snbr_digits(intmax_t nbr)
{
	int num_c;

	num_c = 1;
	while ((nbr = nbr / 10))
		num_c++;
	return (num_c);
}

int		unbr_digits(uintmax_t nbr, char fs)
{
	int 		num_c;

	num_c = 1;
	if (fs == 'x' || fs == 'X')
		num_c = get_hex_len(nbr);
	else
		while ((nbr = nbr / 10))
			num_c++;
	return (num_c);
}

void	min_field_width(t_format_s *ret)
{
	char	flag;

	flag = ' ';
	if (ret->precision > 0 && ret->precision > ret->num_digit)
		ret->precision -= ret->num_digit;
	else if (ret->format_s == 's' && ret->precision > 0)
		ret->num_digit = ret->precision;
	if (ret->format_s == 's' && ret->width_s >= ret->num_digit)
	{
		if (ret->precision != -2)
			ret->width_s -= ret->num_digit;
		ret->num_chr += ret->width_s;
		while (ret->width_s--)
			write(1, &flag, 1);
	}
	else if (ret->width_s >= ret->num_digit && ret->width_s > ret->precision)
	{
		if (ret->s_numarg < 0)
			ret->width_s--;
		if (ret->precision < 0 || ret->precision < ret->num_digit)
			ret->width_s -= ret->num_digit;
		else
			ret->width_s -= ret->precision + ret->num_digit;
		ret->num_chr += ret->width_s;
		if (ret->flag_s & ZERO)
			flag = '0';
		while (ret->width_s--)
			write(1, &flag, 1);
	}
}
