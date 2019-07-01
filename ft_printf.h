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
# define LONG_MAX (long)((unsigned long)~0 >> 1)
# define LONG_MIN -(long)((unsigned long)~0 >>1) -1
# define ULONG_MAX (unsigned long)~0
# define CONTAINS_FLAG(x) ('#' == x) || ('0' == x) || ('-' == x) || ('+' == x) || (' ' == x)
# define IS_BASED_10(x) ('d' == x) || ('i' == x) || ('u' == x)
# define IS_BASED_16(x) ('x' == x) || ('X' == x) || ('p' == x)
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
	char		length_s;
	int			format_s;
	int			num_args;
}				t_format_s;

typedef enum format_spec {
	C = 1 << 0,
	S = 1 << 1,
	P = 1 << 2,
	D = 1 << 3,
	I = 1 << 4,
	O = 1 << 5,
	U = 1 << 6,
	x = 1 << 7,
	X = 1 << 8,
}f_spec;
void		parse_f_specifiers(const char **fmt, t_format_s *fs);
void		print_args(t_format_s *ret, va_list args, int *n);

#endif