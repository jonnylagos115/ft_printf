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
	int sign;
	int n;

	n = 0;
	sign = 1;
	if (**str == '-')
		sign *= -1;
	while (ft_isdigit(**str))
	{
		n = (n * 10) + **str - '0';
		(*str)++;
	}
	fs->width_s = (n * sign);
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
		if (**str == 'h')
		{
			if (*(*str + 1) == 'h')
			{
				fs->length_s = HH;
				(*str)++;
			}
			else
				fs->length_s = H;
		}
		else if (**str == 'l')
		{
			if (*(*str + 1) == 'l')
			{
				fs->length_s = ll;
				(*str)++;
			}
			else
				fs->length_s = l;
		}
		else
			fs->length_s = L;
		(*str)++;
	}
	else
		fs->length_s = 0;
}

void	check_for_spec(const char **str, t_format_s *fs)
{
	if (IS_SIGNED(**str) || IS_UNSIGNED(**str) || **str == 's' 
	|| **str == 'f' || **str == 'p' || **str == '%')
	{
		fs->format_s = **str;
		(*str)++;
	}
	else
		fs->format_s = 0;
}

void		parse_f_specifiers(const char **fmt, t_format_s *fs)
{
	check_for_flags(fmt, fs);
	check_for_width(fmt, fs);
	check_for_precision(fmt, fs);
	check_for_length(fmt, fs);
	check_for_spec(fmt, fs);
}