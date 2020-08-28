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

void	print_args(t_fsptr fsptr)
{
	//print_flags(ret);
	fsptr->handle_mw_p(fsptr);
	if (!(fsptr->flag_spec & MINUS) && fsptr->sfc & MINWIDTH)
		print_minw(fsptr); //where it prints min_width
	else
		fsptr->no_print = false;
	if (fsptr->sfc & PREC)
		print_prec(fsptr);
	if (!(fsptr->sfc & NO_PRINT))
	{
		if (fsptr->format_spec == 's' || fsptr->format_spec == 'p')
			ft_display_str(fsptr);
		else if (fsptr->format_spec == 'd' || fsptr->format_spec == 'i')
			ft_print_signed_nbr(fsptr, fsptr->args.signed_arg);
		else if (fsptr->format_spec == 'u')
			ft_print_unsigned_nbr(fsptr, fsptr->args.unsigned_arg);
		else if (fsptr->format_spec == 'x' || fsptr->format_spec == 'X')
			ft_printhex(fsptr, fsptr->args.unsigned_arg);
		else if (fsptr->format_spec == 'c' || fsptr->format_spec == '%')
		{
			if (fsptr->format_spec == '%')
				fsptr->args.c_arg = '%';
			ft_putchar(fsptr->args.c_arg);
			fsptr->num_chr++;
		}
	}
	if ((fsptr->flag_spec & MINUS) && (fsptr->sfc & MINWIDTH) && (!fsptr->no_print))
		print_minw(fsptr);
}
