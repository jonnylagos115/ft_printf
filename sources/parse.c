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

#include "../ft_printf.h"
#include <printf.h>

void	check_for_flags(const char **str, t_format_s *fs)
{
	if (CONTAINS_FLAG(**str))
	{
		fs->flag_s = **str;
		(*str)++;
	}
	else
		fs->flag_s = 0;
}

void	check_for_width(const char **str, t_format_s *fs)
{
	if (ft_isdigit(**str))
	{
		fs->width_s = **str + '0';
		(*str)++;
	}
	else
		fs->width_s = 0;
}

void	check_for_precision(const char **str, t_format_s *fs)
{
	if (**str == '.')
	{
		fs->precision = 1;
		(*str)++;
	}
	else
		fs->precision = 0;
}

void	check_for_length(const char **str, t_format_s *fs)
{
	if (CONTAINS_LENGTH(**str))
	{
		fs->length_s = **str;
		(*str)++;
	}
	else
		fs->length_s = 0;
}

void	check_for_spec(const char ***str, t_format_s *fs)
{
	if (IS_BASED_10(***str) || IS_BASED_16(***str))
	{
		fs->format_s = ***str;
		(**str)++;
	}
	else
		fs->format_s = 0;
}

void	parse_f_specifiers(const char **fmt, t_format_s *fs)
{
	(*fmt)++;
	check_for_flags(fmt, fs);
	check_for_width(fmt, fs);
	check_for_precision(fmt, fs);
	check_for_spec(&fmt, fs);
}