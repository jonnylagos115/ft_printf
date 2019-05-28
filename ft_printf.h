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
# define UNSIGNED(C) (C == 'u' || C == 'o' || C == 'x' || C == 'X') 
# include <stdarg.h>
# include "./libft_1/includes/libft.h"

typedef struct  test
{
	int 		hi;
	char		*hat;
}Test;

#endif