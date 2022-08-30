/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetElementF.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:54:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/30 09:14:42 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    GetB(t_map *map, int i)
{
    int j;

    j = 0;
    while (map->ar[i] != ' ' && map->ar[i] != '\t' && map->ar[i])
    {
        map->number[j] = map->ar[i];
        i++;
        j++;
    }
    checkColorRange(ft_atoi(map->number));
    map->F.B = ft_atoi(map->number);
    ft_bzero(map->number, 10);
}


void    GetG(t_map *map, int i)
{
    int j;

    j = 0;
    while (map->ar[i])
    {
        if (map->ar[i] == ',')
        {
            checkColorRange(ft_atoi(map->number));
            map->F.G = ft_atoi(map->number);
            ft_bzero(map->number, 10);
            i++;
            break;    
        }
        map->number[j] = map->ar[i];
        i++;
        j++;
        
    }
    GetB(map, i);
}

void GetF(t_map *map)
{

    int i;

    i = 0;
    while (map->ar[i])
    {
        if (map->ar[i] == ',')
        { 
            checkColorRange(ft_atoi(map->number));
            map->F.R = ft_atoi(map->number);
            ft_bzero(map->number, 10);
            i++;
            break;    
        }
        map->number[i] = map->ar[i];
        i++;
    }
    GetG(map, i);
}


void GetInfo(t_map *map, char c)
{
    int i;
    int j;

    map->check++;
    i = map->i;
    j = map->j;
    if (c == 'N')
        map->Ntexture = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
    else if (c == 'S')
        map->Stexture = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
    else if (c == 'W')
        map->Wtexture = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
    else if (c == 'E')
        map->Etexture = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
    else if (c == 'F')
    {
        map->ar = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
        GetF(map);
    }
    else if (c == 'C')
    {
        map->ar2 = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
        GetC(map);
    }
}