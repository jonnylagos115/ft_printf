/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:03:33 by jlagos            #+#    #+#             */
/*   Updated: 2020/08/29 13:03:37 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void		handle_flags(t_fsptr fsptr)
{
	if (fsptr->flag_spec & PLUS || fsptr->flag_spec & SPACE)
	{
		if (!(fsptr->sfc & PREC)
		|| fsptr->prec_spec < fsptr->args.num_bytes)
			fsptr->args.num_bytes++;
		if (fsptr->flag_spec & PLUS &&
		fsptr->args.signed_arg < 0)
			fsptr->flag_spec &= ~(PLUS);
	}
	if ((fsptr->format_spec == 'x' || fsptr->format_spec == 'X')
	&& fsptr->flag_spec & SHARP)
		fsptr->args.num_bytes += 2;
}

void		print_flags(t_fsptr fsptr)
{
	if (fsptr->flag_spec & PLUS)
	{
		write(1, "+", 1);
		fsptr->flag_spec &= ~(PLUS);
	}
	else if (fsptr->flag_spec & SPACE)
	{
		write(1, " ", 1);
		fsptr->flag_spec &= ~(SPACE);
	}
	if ((fsptr->format_spec == 'x' || fsptr->format_spec == 'X')
	&& fsptr->flag_spec & SHARP)
	{
		write(1, "0", 1);
		write(1, &fsptr->format_spec, 1);
		fsptr->flag_spec &= ~(SHARP);
	}
}
