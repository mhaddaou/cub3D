/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:56:05 by izail             #+#    #+#             */
/*   Updated: 2021/11/24 04:17:39 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*p;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	p = (char *)malloc(total * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (total--)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
