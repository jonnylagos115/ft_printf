/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 18:01:41 by jlagos            #+#    #+#             */
/*   Updated: 2019/05/31 18:01:44 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <printf.h>

void	check_minfield_width(char **format, int	*bytes)
{
    int		num;

	num = 0;
    while (ft_isdigit(**format))
	{
		num = (num * 10) + (**format - '0');
		(*format)++;
	}
	if (num)
		return;
	bytes += num - 1;
	while (num-- != 1)
		ft_putchar(' ');
}


