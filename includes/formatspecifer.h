/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatspecifer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:38:46 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 17:38:52 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATSPECIFER_H
# define FORMATSPECIFER_H
# include "ft_printf.h"

typedef struct s_formatspecifier* t_fsptr;
typedef void (*t_handle_minw_prec) (t_fsptr fsptr);
typedef struct	s_formatspecifierargs
{
	char			*cstr_arg;
	char			c_arg;
	intmax_t		signed_arg;
	uintmax_t		unsigned_arg;
	long double		float_arg;
	int				num_bytes;
}				t_formatspecifierargs;

typedef struct	s_formatspecifier
{
	t_formatspecifierargs	args;
	t_handle_minw_prec		handle_mw_p; //function pointer
	char					sfc;
	char					flag_spec;
	int						minw_spec;
	int						prec_spec;
	char					len_spec;
	char					format_spec;
	int						num_chr;
	bool					no_minus;
	bool					no_print;
}				t_formatspecifier;

t_fsptr	create_formatspecifer_obj();
void	destroy_formatspecifer_obj(t_fsptr fsptr);

#endif
