/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:07:14 by jlagos            #+#    #+#             */
/*   Updated: 2020/07/28 16:07:20 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
# include "formatspecifer.h"
# include "handle_minw_prec.h"

typedef struct s_formatspecifier* t_fsptr;

enum		e_length_modifier {
	NONE = 1 << 0,
	HH = 1 << 1,
	H = 1 << 2,
	l = 1 << 3,
	ll = 1 << 4,
};

enum		e_flags {
	MINUS = 1 << 0,
	PLUS = 1 << 1,
	SPACE = 1 << 2,
	SHARP = 1 << 3,
	ZERO = 1 << 4,
};

enum		e_format_sub_specs
{
	FLAGS = 1 << 0,
	MINWIDTH = 1 << 1,
	PREC = 1 << 2,
	LENGTH = 1 << 3,
	NO_PRINT = 1 << 4,
	NEXT_ARG = 1 << 5,
};

int			ft_printf(const char *restrict format, ...);
int			my_vfprintf(const char *fmt, va_list arg);
int			parse_f_specifiers(const char **fmt, t_fsptr fs_ptr);
int			print_args(t_fsptr fsptr);
void		handle_ag(t_fsptr fsptr, va_list args);
intmax_t	get_signed_nbr(va_list args, int length_s);
uintmax_t	get_unsigned_nbr(va_list args, int length_s);
void		ft_print_signed_nbr(t_fsptr fsptr, intmax_t n);
void		ft_print_float_nbr(t_fsptr fsptr, double n);
void		ft_print_unsigned_nbr(t_fsptr fsptr, uintmax_t n);
void		ft_putoctal(t_fsptr fsptr, uintmax_t num);
void		ft_printhex(t_fsptr fsptr, uintmax_t num);
void		ft_print_cstr(t_fsptr fsptr);
void		ft_print_float_nbr(t_fsptr fsptr, double n);
void		ft_store_memaddr(void *addr, t_fsptr fsptr);
void		handle_w_p(t_fsptr fsptr);
void		handle_flags(t_fsptr fsptr);
void		print_flags(t_fsptr fsptr);
void		print_minw_prec(t_fsptr fsptr);
char		get_hex_digit(int c);
int			get_hex_len(uintmax_t num);
int			handle_num_bytes(t_fsptr fsptr);

#endif
