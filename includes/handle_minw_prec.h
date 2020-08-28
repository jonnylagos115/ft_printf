/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minw_prec.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:15:18 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 20:15:20 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_MINW_PREC_H
# define HANDLE_MINW_PREC_H
# include "ft_printf.h"

typedef struct s_formatspecifier* t_fsptr;
typedef void (*t_handle_minw_prec) (t_fsptr fsptr);

void	handle_minw_prec(t_fsptr fsptr);
void	handle_minw_prec_string(t_fsptr fsptr);
void	handle_minw_prec_pointer(t_fsptr fsptr);
void	print_minw(t_fsptr fsptr);
void 	print_prec(t_fsptr fsptr);
void	sfc_prec_minw(t_fsptr fsptr);

#endif