/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:25:24 by jlagos            #+#    #+#             */
/*   Updated: 2019/08/26 13:25:40 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		main(void)
{
	int		len[7];
	int	i = -1;

	len[0] = printf("%.p\n", NULL);
	len[1] = ft_printf("%.p\n", NULL);
	len[2] = ft_printf("%.3s\n", "hello");
	len[3] = printf("%.3s\n", "hello");
	len[4] = ft_printf("hello, %s.\n", "gavin");
	len[5] = ft_printf("%15.4d\n", -424242);
	len[6] = printf("%.4s\n", "42 is the answer");
	while (++i < 7)
		printf("len[%d]: %d\n", i, len[i]);
	return (0);
}

/*
0042
             42
         424242
424242424
          -0042
        -424242
-424242424
len[0]: 5
len[1]: 16
len[2]: 16
len[3]: 10
len[4]: 16
len[5]: 16
len[6]: 11
*/