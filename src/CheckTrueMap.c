/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:16:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/29 15:24:40 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    CheckFirstLine(char *str)
{
    int i;
    int t;
    t = 0;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
    {
        if (str[i] == '\t')
            t++;   
        i++;
    }
    int l = (t *4);
    
    // printf("%d\n", l);
    while (str[i] != '\n' && str[i])
    {
        if (str[i] != '1')
            if (str[i] == ' ')
            err_hand(7);
        i++;
    }
}
void    CheckTrueMap(t_cub *cub)
{
    CheckFirstLine(cub->map->TrueMap[0]);
}