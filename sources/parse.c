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

void	check_for_flags(const char **str, t_format_s *fs)
{
	fs->flag_s = 0;
	while (CONTAINS_FLAG(**str))
	{
		if (**str == '-')
			fs->flag_s |= MINUS;
		if (**str == '+')
			fs->flag_s |= PLUS;
		if (**str == ' ')
			fs->flag_s |= SPACE;
		if (**str == '#')
			fs->flag_s |= SHARP;
		if (**str == '0')
			fs->flag_s |= ZERO;
		if ((fs->flag_s & ZERO) && (fs->flag_s & MINUS))
			fs->flag_s &= ~(ZERO);
		if ((fs->flag_s & SPACE) && (fs->flag_s & PLUS))
			fs->flag_s &= ~(SPACE);
		(*str)++;
	}
}

void	check_for_wp(const char **str, t_format_s *fs)
{
	int		n;

	n = 0;
	while (ft_isdigit(**str))
	{
		n = (n * 10) + **str - '0';
		(*str)++;
	}
	fs->width_s = n;
	n = 0;
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			n = (n * 10) + **str - '0';
			(*str)++;
		}
		if (!n)
			fs->no_prec = 1;
	}
	fs->precision = n;
}

void	check_for_length(const char **str, t_format_s *fs)
{
	fs->length_s = 0;
	if (CONTAINS_LENGTH(**str))
	{
		if (*(*str + 1) == 'h')
		{
			fs->length_s |= HH;
			(*str)++;
		}
		else if (**str == 'h')
			fs->length_s |= H;
		else if (*(*str + 1) == 'l')
		{
			fs->length_s |= ll;
			(*str)++;
		}
		else if (**str == 'l')
			fs->length_s |= l;
		else if (**str == 'L')
			fs->length_s |= L;
		(*str)++;
	}
}

int		check_for_spec(const char **str, t_format_s *fs)
{
	if (IS_FORMAT_SPEC(**str))
	{
		fs->format_s = **str;
		(*str)++;
		if (fs->format_s == 'U')
			fs->length_s = l;
	}
	else
	{
		fs->format_s = 0;
		return (1);
	}
	fs->args = NULL;
	return (0);
}

int		parse_f_specifiers(const char **fmt, t_format_s *fs)
{
	check_for_flags(fmt, fs);
	check_for_wp(fmt, fs);
	check_for_length(fmt, fs);
	return (check_for_spec(fmt, fs));
}
