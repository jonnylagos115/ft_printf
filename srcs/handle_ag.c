/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:08:57 by jlagos            #+#    #+#             */
/*   Updated: 2019/09/17 16:09:04 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_ag(t_fsptr fsptr, va_list args)
{
	char	*tmp;

	if (fsptr->format_spec == 'd' || fsptr->format_spec == 'i')
	{
		fsptr->args.signed_arg = get_signed_nbr(args, fsptr->len_spec);
		fsptr->args.num_bytes = snbr_digits(fsptr->args.signed_arg);
		fsptr->handle_mw_p = handle_minw_prec;
	}
	else if (fsptr->format_spec == 'u' || fsptr->format_spec == 'x' ||
	fsptr->format_spec == 'X')
	{
		fsptr->args.unsigned_arg = get_unsigned_nbr(args,  fsptr->len_spec);
		fsptr->args.num_bytes = unbr_digits(fsptr->args.unsigned_arg, fsptr->format_spec);
		fsptr->handle_mw_p = handle_minw_prec;
	}
	else if (fsptr->format_spec == 'c' || fsptr->format_spec == '%')
	{
		if (fsptr->format_spec == 'c')
			fsptr->args.c_arg = va_arg(args, int);
		fsptr->handle_mw_p = handle_minw_prec_string;
		fsptr->args.num_bytes = 1;
	}
	else
	{
		if (fsptr->format_spec == 'p')
		{
			ft_store_memaddr(va_arg(args, char *), fsptr);
			fsptr->handle_mw_p = handle_minw_prec;
		}
		else if (fsptr->format_spec == 's')
		{
			tmp = va_arg(args, char *);
			fsptr->args.cstr_arg = ft_strdup(tmp);
			fsptr->args.num_bytes = ft_strlen(fsptr->args.cstr_arg);
			fsptr->handle_mw_p = handle_minw_prec_string;
			if (!fsptr->args.cstr_arg)
				fsptr->args.num_bytes = 6;
		}
	}
}
