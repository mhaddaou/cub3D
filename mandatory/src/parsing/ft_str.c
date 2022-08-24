/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 05:44:27 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/24 15:17:46 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

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

void ft_strerror(int err)
{
        if (err == 1)
                ft_putstr_fd("Error\nThe extension of the map is not correct.\n", 2);
        if (err == 2)
                ft_putstr_fd("Error\nThe Map is empty.\n", 2);
        if (err == 3)
                ft_putstr_fd("Error\nThe window can't be open", 2);    
        exit(EXIT_FAILURE);
}
