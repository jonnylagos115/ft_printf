/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:53:10 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/12 16:53:11 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		min_field_width(t_format_s *ret, intmax_t nbr)
{
	int		nbr_c;

	nbr_c = 1;
	if (ret->format_s != 'p')
	{
		if (nbr < 0)
			nbr_c++;
		while ((nbr = nbr / 10))
			nbr_c++;
	}
	else
		nbr_c = nbr;
	if (ret->width_s <= nbr_c)
	{
		ret->width_s = 0;
		return (0);
	}
	ret->width_s -= nbr_c;
	nbr_c = ret->width_s;
	while (ret->width_s--)
		write(1, " ", 1);
	ret->width_s = 0;
	return (nbr_c);
}
