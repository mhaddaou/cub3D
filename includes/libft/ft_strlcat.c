/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:24:53 by izail             #+#    #+#             */
/*   Updated: 2021/11/15 16:57:37 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	src_size;
	unsigned int	dst_size;
	unsigned int	i;

	i = 0;
	src_size = 0;
	dst_size = 0;
	while (src[src_size])
		src_size++;
	if (dstsize == 0)
		return (src_size);
	while (dst_size < dstsize && dst[dst_size])
		dst_size++;
	if (dstsize <= dst_size)
		return (dstsize + src_size);
	i = 0;
	while (dstsize && (--dstsize - dst_size) && src[i])
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}
