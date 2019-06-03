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

void		print_bits(unsigned char octet)
{
	int 			i;
	unsigned char 	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

void	parse_format_specifiers(char *format, format_s *detect, int *index)
{
	/*if (IS_BASED_10(format[*index]))
    {
        
    }
    if (IS_BASED_16(format[*index]))
    {

    }*/
    detect->format_s = 0;
    if (format[*index] == 'c')
        detect->format_s = detect->format_s | C; 
    if (format[*index] == 's')
        detect->format_s |= S;
    (*index)++;
}