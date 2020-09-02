/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:45:45 by jlagos            #+#    #+#             */
/*   Updated: 2018/12/11 11:30:53 by jlagos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl(char const *s)
{
	char			newline;
	size_t			i;

	i = 0;
	newline = '\n';
	while (s[i])
		write(1, &s[i++], 1);
	write(1, &newline, 1);
}
