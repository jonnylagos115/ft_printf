/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 10:51:25 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/28 10:51:29 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_flags(t_format_s *ret)
{
	if (ret->width_s > 0 && ret->precision > 0 && (ret->flag_s & ZERO))
		ret->flag_s &= ~(ZERO);
	if (ret->flag_s & SHARP)
	{
		if (ret->precision > 0 && ret->format_s == 'o')
			ret->flag_s &= ~(SHARP);
		else if (ret->format_s == 'o')
			ret->num_digit++;
		if ((HEX_NBR(ret->format_s)) && ret->width_s > 0)
			ret->width_s -= 2;
	}
	if (ret->flag_s & PLUS || ret->flag_s & SPACE)
	{
		if (ret->format_s == '%' || ret->format_s == 'c' || ret->format_s == 'u'
		|| ret->s_numarg < 0)
		{
			ret->flag_s &= ~(PLUS);
			ret->flag_s &= ~(SPACE);
		}
		else
		{
			if (ret->width_s > ret->precision || (!ret->width_s && !ret->precision))
			{
				ret->num_chr++;
				if (ret->precision < ret->num_digit)
					ret->num_digit++;
			}
		}
	}
}

void	print_flags(t_format_s *ret)
{
	if (ret->flag_s & PLUS)
	{
		write(1, "+", 1);
		ret->flag_s &= ~(PLUS);
	}
	else if (ret->flag_s & SPACE)
	{
		write(1, " ", 1);
		ret->flag_s &= ~(SPACE);
	}
}
