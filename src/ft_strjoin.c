/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 05:44:27 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/22 06:27:57 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char     *ft_copystr(char *dst, char *src)
{
        int     t;

        t = 0;
        while (src[t])
        {
                dst[t] = src[t];
                t++;
        }
        return (dst);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        size_t  i;
        size_t  j;
        char    *str;
        size_t  len;

        if (!s1 || !s2)
                return (NULL);
        len = ft_strlen (s1) + ft_strlen (s2);
        i = 0;
        j = 0;
        str = (char *) malloc (len + 1);
        if (!str)
                return (NULL);
        ft_copystr (str, (char *)s1);
        while (s1[i])
                i++;
        while (s2[j])
        {
                str[i + j] = s2[j];
                j++;
        }
        str[i + j] = '\0';
        return (str);
}
