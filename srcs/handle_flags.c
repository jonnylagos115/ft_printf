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

#include "../includes/ft_printf.h"

void	print_flags(t_fsptr fs_ptr)
{
	if (fs_ptr->args.signed_arg >= 0 && fs_ptr->format_spec != '%' && (fs_ptr->flag_spec & PLUS || fs_ptr->flag_spec & SPACE))
	{
		if (fs_ptr->flag_spec & PLUS)
			write(1, "+", 1);
		else if (fs_ptr->flag_spec & SPACE)
			write(1, " ", 1);
		fs_ptr->num_chr++;
		fs_ptr->args.num_bytes++;
		fs_ptr->flag_spec &= ~(PLUS);
		fs_ptr->flag_spec &= ~(SPACE);
	}
	if (fs_ptr->flag_spec & SHARP)
	{
		if (fs_ptr->prec_spec > 0 && fs_ptr->format_spec == 'o')
			fs_ptr->prec_spec &= ~(SHARP);
	}
}
