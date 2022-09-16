/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:54:47 by izail             #+#    #+#             */
/*   Updated: 2021/11/24 04:21:22 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char
	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*s2;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	s2 = (char *)s1;
	start = 0;
	while (s2[start] && ft_char_in_set(s2[start], set))
		start++;
	end = ft_strlen(s2);
	while (end > start && ft_char_in_set(s2[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s2) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s2[start++];
	str[i] = 0;
	return (str);
}
