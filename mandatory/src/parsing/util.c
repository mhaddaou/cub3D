/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 05:41:59 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/23 12:56:25 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char    *ft_strdup(const char *s1)
{
        char    *str;

        str = (char *) malloc (ft_strlen(s1) + 1);
        if (!str)
                return (NULL);
        ft_memcpy(str, s1, ft_strlen(s1) + 1);
        return (str);
}

char    *ft_strchr(const char *s, int c)
{
        size_t  i;

        i = 0;
        while (((char *)s)[i])
        {
                if (s[i] == (char)c)
                        return ((char *)&s[i]);
                i++;
        }
        if (((char *)s)[i] == '\0' && c == '\0')
                return ((char *)&s[i]);
        return (NULL);
}

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}
void ft_putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((!dst) && (!src))
		return (NULL);
	else
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}