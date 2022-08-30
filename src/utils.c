/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:16:50 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/30 09:15:11 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *ft_strncpy(char *s1, char *s2, int len)
{
    int i;

    i = 0;

    while (i < len)
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

void checkColorRange(int r)
{
    if (r < 0 || r > 255)
        err_hand(11);
}