/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:17:01 by jlagos            #+#    #+#             */
/*   Updated: 2019/05/15 15:17:02 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define NL ft_putchar('\n')
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define UNSIGNED_INT_MAX (unsigned int)~0
# define LLONG_MAX (long)((unsigned long)~0 >> 1)
# define LLONG_MIN -(long)((unsigned long)~0 >>1) -1
# define ULONG_MAX (unsigned long)~0
# define CONTAINS_FLAG(x) ('#' == x) || ('0' == x) || ('-' == x) || ('+' == x) || (' ' == x)
# define IS_SIGNED(x) ('d' == x) || ('i' == x)
# define HEX_NBR(x) ('x' == x) || ('X' == x)
# define NO_NBR(x) ('c' != x) && ('s' != x)
# define IS_UNSIGNED(x) ('u' == x)|| ('o' == x) || ('x' == x) || ('X' == x) || ('U' == x)
# define IS_FORMAT_SPEC(x) ((IS_UNSIGNED(x)) || (IS_SIGNED(x)) ||\
('s' == x) || ('c' == x) || ('f' == x) || ('p' == x) || ('%' == x))
# define CONTAINS_LENGTH(x) ('h' == x ) || ('l' == x) || ('L' == x)
# define SIZE(x) sizeof(x)*8
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h> 
# include <limits.h>
# include "./libft_1/libft.h"

typedef struct s_fspecifier
{
	char			*args;
	char			c;
	intmax_t		s_numarg;
	uintmax_t		u_numarg;
	long double		f_numarg;
	char			flag_s;
	int				width_s;
	int				precision;
	int				length_s;
	int				format_s;
	int				num_chr;
	int				num_digit;
	int				no_minus;
	int				no_print;
	int				no_prec;
}				t_format_s;

enum 		s_length_modifier {
	NONE = 1 << 0,
	HH = 1 << 1,
	H = 1 << 2,
	l = 1 << 3,
	ll = 1 << 4,
	L = 1 << 5,
	z = 1 << 6,
	j = 1 << 7,
	U = 1 << 8,
};

enum		s_flags {
	MINUS = 1 << 0,
	PLUS = 1 << 1,
	SPACE = 1 << 2,
	SHARP = 1 << 3,
	ZERO = 1 << 4,
};

int 		ft_printf(const char *restrict format, ...);
int 		my_vfprintf(const char *fmt, va_list arg);
int			parse_f_specifiers(const char **fmt, t_format_s *fs);
void		print_args(t_format_s *ret);
void		handle_ag(t_format_s *ret, va_list args);
void		handle_flags(t_format_s *ret);
void		get_signed_nbr(t_format_s *ret, va_list args, int length_s);
void		get_unsigned_nbr(t_format_s *ret, va_list args, int length_s);
void		print_signed_nbr(t_format_s *ret, intmax_t n);
void		handle_w_p(t_format_s *ret);
void		print_flags(t_format_s *ret);
void		print_w_p(t_format_s *ret);
char		get_hex_digit(int c);
int			snbr_digits(intmax_t nbr);
int			unbr_digits(uintmax_t nbr, char fs);

#endif
