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
	if (nbr < 0)
		num_c++;
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
	int		num_c;

	flag = ' ';
	if (IS_SIGNED(ret->format_s))
	{
		num_c = snbr_digits(ret->s_numarg);
		if (ret->flag_s & PLUS || ret->flag_s & SPACE)
			num_c++;
	}
	else if (IS_UNSIGNED(ret->format_s))
		num_c = unbr_digits(ret->u_numarg, ret->format_s);
	else if (ret->format_s == 'p' || ret->format_s == 's')
		num_c = ft_strlen(ret->args);
	else
		num_c = 1;
	if (ret->width_s >= num_c)
	{
		ret->width_s -= num_c;
		ret->num_chr += ret->width_s;
		if (ret->flag_s & ZERO)
			flag = '0';
		while (ret->width_s--)
			write(1, &flag, 1);
	}
	ret->width_s = 0;
}
