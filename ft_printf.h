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
# define NL printf("\n")
# define INT_MAX 2147483647
# define UNSIGNED_INT_MAX (unsigned int)~0
# define LONG_MAX (long)((unsigned long)~0 >> 1)
# define LONG_MIN -(long)((unsigned long)~0 >>1) -1
# define ULONG_MAX (unsigned long)~0
# define SIZE(x) sizeof(x)*8
# include <stdarg.h>
# include "./libft_1/includes/libft.h"

typedef struct  test
{
	int 		hi;
	char		*hat;
}Test;

void     check_minfield_width(char **format, int *bytes);
#endif