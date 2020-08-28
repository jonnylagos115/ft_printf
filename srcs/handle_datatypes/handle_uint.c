/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:14:30 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 19:14:31 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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

int			unbr_digits(uintmax_t nbr, char fs)
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

void		ft_print_unsigned_nbr(t_fsptr fsptr, uintmax_t n)
{
	if (n > 9)
		ft_print_unsigned_nbr(fsptr, n / 10);
	fsptr->num_chr++;
	ft_putchar(n % 10 + '0');
}