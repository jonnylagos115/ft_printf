/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:39:20 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/18 18:39:32 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_flags(t_format_s *ret)
{
	if (ret->s_numarg >= 0 && ret->format_s != '%' && (ret->flag_s & PLUS || ret->flag_s & SPACE))
	{
		if (ret->flag_s & PLUS)
			ft_putchar('+');
		else
			ft_putchar(' ');
		ret->num_chr++;
	}
	if (ret->width_s && !(ret->flag_s & MINUS))
		if (!((ret->flag_s & ZERO) && ret->s_numarg < 0))
			min_field_width(ret);
}