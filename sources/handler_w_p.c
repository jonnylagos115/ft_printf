/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_w_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:08:46 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/28 14:08:48 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_w_p(t_format_s *ret)
{
	char	flag;

	flag = ' ';
	ret->no_minus = 0;
	if ((ret->flag_s & ZERO) && ret->precision <= 0)
	{
		if ((IS_SIGNED(ret->format_s)) && ret->s_numarg < 0)
		{
			write(1, "-", 1);
			ret->no_minus = 1;
		}
		if ((HEX_NBR(ret->format_s)) && ret->flag_s & SHARP)
		{
			write(1, "0", 1);
			write(1, &ret->format_s, 1);
			ret->num_chr += 2;
			ret->flag_s &= ~(SHARP);
		}
		flag = '0';
	}
	if (!(ret->flag_s & MINUS))
	{
		if (ret->flag_s & ZERO)	//if zero flag set, print '+' first before printing min_width
			print_flags(ret);
		while (ret->width_s--)
			write(1, &flag, 1);
	}
	else
		ret->flag_s &= ~(MINUS);
	if (!(ret->flag_s & ZERO))
		print_flags(ret);
	if (ret->precision > 0 && NO_NBR(ret->format_s))
	{
		if ((IS_SIGNED(ret->format_s)) && ret->s_numarg < 0)
		{
			write(1, "-", 1);
			ret->no_minus = 1;
		}
		if (ret->format_s == 'p' || ((HEX_NBR(ret->format_s)) && ret->flag_s & SHARP))
		{
			write(1, "0x", 2);
			ret->args = ret->args + 2;
			if (HEX_NBR(ret->format_s))
				ret->num_chr += 2;
		}
		while (ret->precision--)
		    write(1, "0", 1);
	}
}

void	handle_w_p(t_format_s *ret)
{
	if ((IS_SIGNED(ret->format_s)) && ret->s_numarg < 0 && ret->width_s > 0)
		ret->width_s--;
	if (ret->width_s >= ret->precision && ret->precision >= 0) //for only min width, or if min width is greater than precision
	{
		if (ret->precision > ret->num_digit && NO_NBR(ret->format_s))
		{
			ret->precision -= ret->num_digit;
			ret->width_s -= ret->precision + ret->num_digit;
			if (ret->flag_s & SPACE || ret->flag_s & PLUS)
				ret->width_s--;
		}
		else
		{
			ret->width_s -= ret->num_digit;
			if (ret->width_s < 0)
				ret->width_s = 0;
			ret->precision = 0;
		}
	}
	else if (ret->width_s <= ret->precision && ret->width_s >= 0)
	{
		if (NO_NBR(ret->format_s))
		{
			if (ret->format_s == 'p')
				ret->num_digit -= 2;
			ret->precision -= ret->num_digit;
			ret->width_s = 0;
		}
		else if (ret->width_s > ret->num_digit)
			ret->width_s -= ret->num_digit;
		else
			ret->width_s = 0;
	}
	ret->num_chr += ret->width_s;
	if ((NO_NBR(ret->format_s)) && ret->precision > 0)
		ret->num_chr += ret->precision;
}
