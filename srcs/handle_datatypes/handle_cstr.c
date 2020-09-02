/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:13:59 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 19:14:00 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		ft_print_cstr(t_fsptr fsptr)
{
	int		i;

	if (fsptr->args.cstr_arg)
	{
		i = -1;
		if (fsptr->format_spec == 'p')
			if (fsptr->sfc & PREC)
				i += 2;
		while (++i != fsptr->args.num_bytes)
			ft_putchar(fsptr->args.cstr_arg[i]);
		ft_strdel(&fsptr->args.cstr_arg);
	}
	else if (fsptr->format_spec == 'c' || fsptr->format_spec == '%')
	{
		if (fsptr->format_spec == '%')
			fsptr->args.c_arg = '%';
		ft_putchar(fsptr->args.c_arg);
	}
	else if (fsptr->format_spec == 'p')
		write(1, "0x0", 3);
	fsptr->num_chr += fsptr->args.num_bytes;
}
