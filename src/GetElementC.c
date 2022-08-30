/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetElementC.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:18:34 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/30 09:13:40 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    GetCB(t_map *map, int i)
{
    int j;

    j = 0;
    while (map->ar2[i] != ' ' && map->ar2[i] != '\t' && map->ar2[i])
    {
        map->number[j] = map->ar2[i];
        i++;
        j++;
    }
    checkColorRange(ft_atoi(map->number));
    map->F.B = ft_atoi(map->number);
    ft_bzero(map->number, 10);
}
void    GetCG(t_map *map, int i)
{
    int j;

    j = 0;
    while (map->ar2[i])
    {
        if (map->ar2[i] == ',')
        {
            checkColorRange(ft_atoi(map->number));
            map->C.G = ft_atoi(map->number);
            ft_bzero(map->number, 10);
            i++;
            break;    
        }
        map->number[j] = map->ar2[i];
        i++;
        j++;
        
    }
    GetCB(map, i);
}
void GetC(t_map *map)
{
    int i;

    i = 0;
    while (map->ar2[i])
    {
        if (map->ar2[i] == ',')
        {
            checkColorRange(ft_atoi(map->number));
            map->C.R = ft_atoi(map->number);
            ft_bzero(map->number, 10);
            i++;
            break;    
        }
        map->number[i] = map->ar2[i];
        i++;
    }
    GetCG(map, i);
}
