/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:32:39 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/20 12:32:53 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	prec_field_control(t_format_s *ret)
{
	if (ret->precision < 0 && (!ret->s_numarg || !ret->u_numarg))
	{
		ret->format_s = 0;
		
	}
	if (ret->precision > ret->num_digit)
    {
		if (ret->s_numarg < 0)
		{
			write(1, "-", 1);
			ret->s_numarg *= -1;
			ret->num_chr++;
        }
        ret->precision -= ret->num_digit;
        ret->num_chr += ret->precision;
        while (ret->precision--)
            write(1, "0", 1);
	}
}
