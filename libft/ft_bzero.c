/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:42:20 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/09 18:45:55 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*zero;
	size_t			i;

	zero = (unsigned char*)s;
	i = 0;
	if (n != 0)
	{
		while (i < n)
			zero[i++] = '\0';
	}
}
