/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:34:20 by jlagos            #+#    #+#             */
/*   Updated: 2019/06/03 15:34:22 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_args(t_fsptr fsptr)
{
	fsptr->handle_mw_p(fsptr);
	if (!(fsptr->flag_spec & MINUS) && fsptr->sfc & MINWIDTH)
		print_minw(fsptr);
	if (fsptr->sfc & PREC)
		print_prec(fsptr);
	if (fsptr->sfc & FLAGS)
		print_flags(fsptr);
	if (!(fsptr->sfc & NO_PRINT))
	{
		if (fsptr->format_spec == 'd' || fsptr->format_spec == 'i')
			ft_print_signed_nbr(fsptr, fsptr->args.signed_arg);
		else if (fsptr->format_spec == 'u')
			ft_print_unsigned_nbr(fsptr, fsptr->args.unsigned_arg);
		else if (fsptr->format_spec == 'x' || fsptr->format_spec == 'X')
			ft_printhex(fsptr, fsptr->args.unsigned_arg);
		else
			ft_print_cstr(fsptr);
	}
	if (fsptr->flag_spec & MINUS && fsptr->sfc & MINWIDTH)
		print_minw(fsptr);
	return (fsptr->num_chr);
}
