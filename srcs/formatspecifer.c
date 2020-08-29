/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormatSpecifer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:39:37 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 17:39:40 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatspecifer.h"

t_fsptr	create_formatspecifer_obj(void)
{
	t_fsptr fs_ptr;

	fs_ptr = malloc(sizeof(*fs_ptr));
	if (fs_ptr)
	{
		fs_ptr->handle_mw_p = handle_minw_prec;
		fs_ptr->args.c_arg = 0;
		fs_ptr->args.cstr_arg = NULL;
		fs_ptr->args.signed_arg = 0;
		fs_ptr->args.unsigned_arg = 0;
		fs_ptr->args.num_bytes = 0;
		fs_ptr->sfc = 0;
		fs_ptr->flag_spec = 0;
		fs_ptr->minw_spec = 0;
		fs_ptr->prec_spec = 0;
		fs_ptr->len_spec = 0;
		fs_ptr->num_chr = 0;
		fs_ptr->no_minus = true;
		fs_ptr->no_print = true;
	}
	return (fs_ptr);
}

void	destroy_formatspecifer_obj(t_fsptr *fsptr)
{
	free(*fsptr);
	*fsptr = NULL;
}
