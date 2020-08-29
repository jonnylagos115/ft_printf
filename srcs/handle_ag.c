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

void	handle_negstar(t_fsptr fsptr, va_list args)
{
	if (fsptr->minw_spec == '*')
	{
		fsptr->minw_spec = va_arg(args, int);
		if (fsptr->minw_spec < 0)
		{
			fsptr->flag_spec |= MINUS;
			if (fsptr->flag_spec & ZERO)
				fsptr->flag_spec &= ~(ZERO);
			fsptr->minw_spec -= fsptr->minw_spec * 2;
		}
	}
	if (fsptr->prec_spec == '*')
	{
		fsptr->prec_spec = va_arg(args, int);
		if (fsptr->prec_spec < 0)
			fsptr->sfc &= ~(PREC);
	}
}

int		handle_num_bytes(t_fsptr fsptr)
{
	int					num_c;
	uintmax_t			u_nbr;
	intmax_t			s_nbr;

	num_c = 1;
	u_nbr = fsptr->args.unsigned_arg;
	s_nbr = fsptr->args.signed_arg;
	if (fsptr->format_spec == 'u')
		while (u_nbr = u_nbr / 10)
			num_c++;
	else if (fsptr->format_spec == 'd' || fsptr->format_spec == 'i')
		while (s_nbr = s_nbr / 10)
			num_c++;
	else if (fsptr->format_spec == 'x' || fsptr->format_spec == 'X')
		num_c = get_hex_len(u_nbr);
	else if (fsptr->format_spec == 's')
	{
		num_c = ft_strlen(fsptr->args.cstr_arg);
		if (!fsptr->args.cstr_arg)
			num_c = 6;
	}
	return (num_c);
}

void	handle_ag(t_fsptr fsptr, va_list args)
{
	handle_negstar(fsptr, args);
	if (fsptr->format_spec == 'd' || fsptr->format_spec == 'i')
		fsptr->args.signed_arg = get_signed_nbr(args, fsptr->len_spec);
	else if (fsptr->format_spec == 'u' || fsptr->format_spec == 'x' ||
	fsptr->format_spec == 'X')
		fsptr->args.unsigned_arg = get_unsigned_nbr(args, fsptr->len_spec);
	else if (fsptr->format_spec == 'c')
	{
		fsptr->args.c_arg = va_arg(args, int);
		fsptr->handle_mw_p = handle_minw_prec_string;
	}
	else if (fsptr->format_spec == 's')
	{
		fsptr->args.cstr_arg = ft_strdup(va_arg(args, char *));
		fsptr->handle_mw_p = handle_minw_prec_string;
	}
	fsptr->args.num_bytes = handle_num_bytes(fsptr);
	if (fsptr->format_spec == 'p')
		ft_store_memaddr(va_arg(args, char *), fsptr);
}
