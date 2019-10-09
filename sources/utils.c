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
	int 				num_c;
	uintmax_t			i;

	num_c = 1;
	if (fs == 'x' || fs == 'X')
		num_c = get_hex_len(nbr);
	else if (fs == 'o')
	{
		num_c--;
		i = 1;
		while (++num_c <= 21 && ((i * 8) < nbr))
			i *= 8;
	}
	else
		while ((nbr = nbr / 10))
			num_c++;
	return (num_c);
}