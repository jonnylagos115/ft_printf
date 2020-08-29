/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 10:51:25 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/28 10:51:29 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_flags(t_fsptr fsptr)
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

void	print_flags(t_fsptr fsptr)
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
