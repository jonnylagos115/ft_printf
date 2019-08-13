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
# define IS_SIGNED(x) ('d' == x) || ('i' == x) || ('c' == x)
# define IS_UNSIGNED(x) ('u' == x)|| ('o' == x) || ('x' == x) || ('X' == x)
# define CONTAINS_LENGTH(x) ('h' == x ) || ('l' == x) || ('L' == x)
# define SIZE(x) sizeof(x)*8
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h> 
# include <limits.h>
# include "./libft_1/includes/libft.h"

typedef struct s_fspecifier
{
	char		*args;
	char		flag_s;
	int			width_s;
	int			precision;
	int			length_s;
	int			format_s;
	int			num_args;
}				t_format_s;

enum 		s_length_modifier {
	NONE = 1 << 0,
	HH = 1 << 1,
	H = 1 << 2,
	l = 1 << 3,
	ll = 1 << 4,
	L = 1 << 5
};

void		parse_f_specifiers(const char **fmt, t_format_s *fs);
void		print_args(t_format_s *ret, va_list args, int *n);
intmax_t	get_signed_nbr(va_list args, int length_s);
uintmax_t	get_unsigned_nbr(va_list args, int length_s);
void		print_signed_nbr(t_format_s *ret, intmax_t n, int *nbr_char);
void		print_unsigned_nbr(uintmax_t n, int *nbr_char);
int			min_field_width(t_format_s *ret, intmax_t nbr);

#endif

/*
042
9223372036854775807
-9223372036854775808
042
9223372036854775807
-9223372036854775808
0, 18446744073709551615
0, 1777777777777777777777
0, ffffffffffffffff
0, FFFFFFFFFFFFFFFF
 */