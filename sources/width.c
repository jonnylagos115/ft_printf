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

int		snbr_digits(intmax_t nbr)
{
	int num_c;

	num_c = 1;
	if (nbr < 0)
		num_c++;
	while ((nbr = nbr / 10))
		num_c++;
	return (num_c);
}

int		unbr_digits(uintmax_t nbr)
{
	int num_c;

	num_c = 1;
	while ((nbr = nbr / 10))
		num_c++;
	return (num_c);
}

void	min_field_width(t_format_s *ret)
{
	int		num_c;

	if (IS_SIGNED(ret->format_s))
		num_c = snbr_digits(ret->s_numarg);
	else if (IS_UNSIGNED(ret->format_s))
		num_c = unbr_digits(ret->u_numarg);
	else if (ret->format_s == 'p')
		num_c = ft_strlen(ret->args) + 2;
	else
		num_c = 0;
	if (ret->width_s <= num_c)
	{
			ret->width_s -= num_c;
		num_c = ret->width_s;
		while (ret->width_s--)
			write(1, " ", 1);
		ret->num_chr += num_c;
	}
	ret->width_s = 0;
}
