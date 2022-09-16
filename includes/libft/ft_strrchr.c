/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:25:31 by izail             #+#    #+#             */
/*   Updated: 2021/11/24 04:23:28 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*p_char;

	str = (char *) s;
	p_char = NULL;
	while (*str != '\0')
	{
		if (*str == (char )c)
			p_char = str;
		str++;
	}
	if (c == '\0')
		return (str);
	return (p_char);
}
