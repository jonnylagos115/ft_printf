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

void		ft_display_str(t_fsptr fsptr)
{
	int		i;

	if (fsptr->args.cstr_arg)
	{
		i = -1;
		if (fsptr->format_spec == 'p') //adding '0x' count to num_bytes
		{
			if (fsptr->sfc & PREC)	
				i += 2;
			//fsptr->args.num_bytes += 2;
		}
		while (++i != fsptr->args.num_bytes)
			ft_putchar(fsptr->args.cstr_arg[i]);
		ft_strdel(&fsptr->args.cstr_arg);
	}
	else if (fsptr->format_spec == 's')
		write(1, "(null)", 6);
	else if (fsptr->format_spec == 'p')
		write(1, "(nil)", 5);
	fsptr->num_chr += fsptr->args.num_bytes;
}
