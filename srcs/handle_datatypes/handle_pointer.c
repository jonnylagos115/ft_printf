/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 19:14:47 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 19:14:49 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_store_memaddr(void *addr, t_fsptr fsptr)
{
	char		buf[16];
	int			i;
	int			j;
	uintptr_t	p;

	p = (uintptr_t)addr;
	i = (sizeof(p) << 3) - 4;
	j = 1;
	if (p)
	{
		ft_memcpy(buf, "0x", 2);
		while ((i >= 0) && get_hex_digit((p >> i) & 0xf) == '0')
			i -= 4;
		while (i >= 0)
		{
			buf[++j] = get_hex_digit((p >> i) & 0xf);
			i -= 4;
		}
		buf[j + 1] = '\0';
		fsptr->args.cstr_arg = ft_strdup(buf);
		fsptr->args.num_bytes = ft_strlen(fsptr->args.cstr_arg);
	}
	else
		fsptr->args.num_bytes = 5;
}
