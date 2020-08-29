/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:14:09 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 19:14:10 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		get_hex_len(uintmax_t num)
{
	int		i;
	int		len;

	i = (sizeof(num) << 3) - 4;
	len = 0;
	while ((num && i >= 0) && get_hex_digit((num >> i) & 0xf) == '0')
		i -= 4;
	while (num && i >= 0)
	{
		len++;
		i -= 4;
	}
	if (!num)
		len++;
	return (len);
}

char	get_hex_digit(int c)
{
	if (c >= 0 && c <= 9)
		return (c + '0');
	else
		return ('a' + c - 10);
}

void	ft_printhex(t_fsptr fsptr, uintmax_t num)
{
	uintmax_t remainder;

	remainder = num % 16;
	if (num / 16)
		ft_printhex(fsptr, num / 16);
	if (fsptr->args.unsigned_arg && fsptr->flag_spec & SHARP)
	{
		write(1, "0", 1);
		write(1, &fsptr->format_spec, 1);
		fsptr->num_chr++;
		fsptr->flag_spec &= ~(SHARP);
	}
	if (remainder > 9)
	{
		remainder += 87;
		if (fsptr->format_spec == 'X')
			remainder -= 32;
		ft_putchar(remainder);
	}
	else
		ft_putchar(remainder + '0');
	fsptr->num_chr++;
}
