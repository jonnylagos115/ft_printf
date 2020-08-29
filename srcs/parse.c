/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:22:33 by jlagos            #+#    #+#             */
/*   Updated: 2019/06/03 12:22:34 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_for_flags(const char **str, t_fsptr fs_ptr)
{
	if (**str == '#' || **str == '0' || **str == '-'
	|| **str == '+' || **str == ' ')
		fs_ptr->sfc |= FLAGS;
	while (**str == '#' || **str == '0' || **str == '-'
	|| **str == '+' || **str == ' ')
	{
		if (**str == '-')
			fs_ptr->flag_spec |= MINUS;
		if (**str == '+')
			fs_ptr->flag_spec |= PLUS;
		if (**str == ' ')
			fs_ptr->flag_spec |= SPACE;
		if (**str == '#')
			fs_ptr->flag_spec |= SHARP;
		if (**str == '0')
			fs_ptr->flag_spec |= ZERO;
		if ((fs_ptr->flag_spec & ZERO) && (fs_ptr->flag_spec & MINUS))
			fs_ptr->flag_spec &= ~(ZERO);
		if ((fs_ptr->flag_spec & SPACE) && (fs_ptr->flag_spec & PLUS))
			fs_ptr->flag_spec &= ~(SPACE);
		(*str)++;
	}
}

void	check_for_minw_prec(const char **str, t_fsptr fs_ptr)
{
	if (ft_isdigit(**str) || **str == '*')
	{
		fs_ptr->sfc |= MINWIDTH;
		if (**str == '*')
		{
			fs_ptr->minw_spec = **str;
			(*str)++;
		}
	}
	while (ft_isdigit(**str))
		fs_ptr->minw_spec = (fs_ptr->minw_spec * 10) + *(*str)++ - '0';
	if (**str == '.')
	{
		fs_ptr->sfc |= PREC;
		(*str)++;
		while (ft_isdigit(**str))
			fs_ptr->prec_spec = (fs_ptr->prec_spec * 10) + *(*str)++ - '0';
		if (**str == '*')
		{
			fs_ptr->prec_spec = **str;
			(*str)++;
		}
	}
}

void	check_for_length(const char **str, t_fsptr fs_ptr)
{
	if (**str == 'h' || **str == 'l')
		fs_ptr->sfc |= LENGTH;
	while (**str == 'h' || **str == 'l')
	{
		if (**str == 'h')
		{
			(*str)++;
			if (**str == 'h')
				fs_ptr->len_spec |= HH;
			else
				fs_ptr->len_spec |= H;
		}
		else if (**str == 'l')
		{
			(*str)++;
			if (**str == 'l')
				fs_ptr->len_spec |= ll;
			else
				fs_ptr->len_spec |= l;
		}
	}
}

int		check_for_spec(const char **str, t_fsptr fs_ptr)
{
	if (**str == 'd' || **str == 'i' || **str == 'u' || **str == 'x'
	|| **str == 'X' || **str == 's' || **str == 'c' || **str == 'p'
	|| **str == '%')
	{
		fs_ptr->format_spec = **str;
		(*str)++;
	}
	else
		return (1);
	return (0);
}

int		parse_f_specifiers(const char **fmt, t_fsptr fs_ptr)
{
	check_for_flags(fmt, fs_ptr);
	check_for_minw_prec(fmt, fs_ptr);
	check_for_length(fmt, fs_ptr);
	return (check_for_spec(fmt, fs_ptr));
}
