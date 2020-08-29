/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minw_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:15:48 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 20:15:50 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/handle_minw_prec.h"

void	print_minw(t_fsptr fsptr)
{
	char	flag;

	flag = ' ';
	if (fsptr->flag_spec & ZERO)
	{
		if ((fsptr->format_spec == 'd' || fsptr->format_spec == 'i')
		&& fsptr->args.signed_arg < 0)
		{
			write(1, "-", 1);
			fsptr->no_minus = false;
		}
		if ((fsptr->format_spec == 'x' || fsptr->format_spec == 'X')
		&& fsptr->flag_spec & SHARP)
		{
			write(1, "0", 1);
			write(1, &fsptr->format_spec, 1);
			fsptr->args.num_bytes += 2;
			fsptr->flag_spec &= ~(SHARP);
		}
		flag = '0';
	}
	fsptr->num_chr += fsptr->minw_spec;
	while (fsptr->minw_spec--)
		write(1, &flag, 1);
	print_flags(fsptr);
}

void	print_prec(t_fsptr fsptr)
{
	if (fsptr->sfc & PREC && fsptr->format_spec != 's')
	{
		print_flags(fsptr);
		if ((fsptr->format_spec == 'd' || fsptr->format_spec == 'i')
		&& fsptr->args.signed_arg < 0)
		{
			write(1, "-", 1);
			fsptr->no_minus = false;
		}
		if (fsptr->format_spec == 'p' || ((fsptr->format_spec == 'x' ||
		fsptr->format_spec == 'X') && fsptr->flag_spec & SHARP))
		{
			write(1, "0x", 2);
			if (fsptr->format_spec == 'x' || fsptr->format_spec == 'X')
				fsptr->args.num_bytes += 2;
			if (fsptr->format_spec == 'p')
				fsptr->prec_spec += 2;
		}
		fsptr->num_chr += fsptr->prec_spec;
		while (fsptr->prec_spec--)
			write(1, "0", 1);
	}
}

void	sfc_prec_minw(t_fsptr fsptr)
{
	handle_flags(fsptr);
	if (fsptr->args.signed_arg < 0 && (fsptr->sfc & MINWIDTH))
		fsptr->minw_spec--;
	if (fsptr->flag_spec & ZERO && (fsptr->sfc & PREC))
		fsptr->flag_spec &= ~(ZERO);
	if ((fsptr->sfc & PREC) && !fsptr->args.signed_arg
	&& !fsptr->args.unsigned_arg)
	{
		if (fsptr->format_spec != 's' && fsptr->format_spec != 'p')
		{
			fsptr->sfc |= NO_PRINT;
			fsptr->args.num_bytes = 0;
		}
	}
	if ((fsptr->sfc & MINWIDTH) && fsptr->format_spec == '%')
		fsptr->minw_spec = 0;
}

void	handle_minw_prec(t_fsptr fsptr)
{
	sfc_prec_minw(fsptr);
	if (fsptr->minw_spec > fsptr->args.num_bytes &&
	fsptr->prec_spec > fsptr->args.num_bytes)
	{
		fsptr->prec_spec -= fsptr->args.num_bytes;
		if (fsptr->minw_spec > (fsptr->prec_spec + fsptr->args.num_bytes))
			fsptr->minw_spec -= fsptr->prec_spec + fsptr->args.num_bytes;
		else
			fsptr->sfc &= ~(MINWIDTH);
	}
	else
	{
		if (fsptr->minw_spec <= fsptr->args.num_bytes)
			fsptr->sfc &= ~(MINWIDTH);
		else
			fsptr->minw_spec -= fsptr->args.num_bytes;
		if (fsptr->prec_spec <= fsptr->args.num_bytes)
			fsptr->sfc &= ~(PREC);
		else
			fsptr->prec_spec -= fsptr->args.num_bytes;
	}
}

void	handle_minw_prec_string(t_fsptr fsptr)
{
	if ((fsptr->sfc & PREC) &&
	(fsptr->prec_spec > fsptr->args.num_bytes))
		fsptr->sfc &= ~(PREC);
	else if ((fsptr->sfc & PREC) &&
	fsptr->prec_spec < fsptr->args.num_bytes)
	{
		fsptr->args.num_bytes = fsptr->prec_spec;
		if (fsptr->args.cstr_arg == NULL)
		{
			fsptr->sfc &= ~(PREC);
			fsptr->sfc |= NO_PRINT;
			fsptr->args.num_bytes = 0;
		}
	}
	if ((fsptr->sfc & MINWIDTH) && ((fsptr->minw_spec < fsptr->args.num_bytes)
	|| (fsptr->format_spec == '%')))
		fsptr->minw_spec = 0;
	else if (fsptr->sfc & MINWIDTH)
	{
		fsptr->minw_spec -= fsptr->args.num_bytes;
		if (fsptr->flag_spec & ZERO)
			fsptr->flag_spec &= ~(ZERO);
	}
}
