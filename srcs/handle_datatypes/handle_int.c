/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:14:15 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 19:14:16 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

intmax_t	get_signed_nbr(va_list args, int length_s)
{
	intmax_t n;

	n = va_arg(args, intmax_t);
	if (!length_s)
		n = (int)n;
	else if (length_s & l)
		n = (long)n;
	else if (length_s & ll)
		n = (long long)n;
	else if (length_s & HH)
		n = (char)n;
	else if (length_s & H)
		n = (short)n;
	return (n);
}

void		ft_print_signed_nbr(t_fsptr fsptr, intmax_t n)
{
	if (n < 0)
	{
		if (fsptr->no_minus)
			write(1, "-", 1);
		if (n == (-INT_MAX - 1))
		{
			write(1, "2", 1);
			n %= 1000000000;
			fsptr->num_chr++;
		}
		else if (n == (-LLONG_MAX - 1LL))
		{
			write(1, "9", 1);
			n %= 1000000000000000000;
			fsptr->num_chr++;
		}
		n *= -1;
		fsptr->num_chr++;
	}
	if (n > 9)
		ft_print_signed_nbr(fsptr, n / 10);
	ft_putchar(n % 10 + '0');
	fsptr->num_chr++;
}
