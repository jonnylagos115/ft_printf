/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:34:30 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/09 20:30:06 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *std2, size_t n)
{
	size_t	i;
	char	*src;
	char	*dest;

	src = (char *)std2;
	dest = (char *)str1;
	i = 0;
	while (i != n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
