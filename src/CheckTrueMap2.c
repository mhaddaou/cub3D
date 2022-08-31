/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:19:16 by izail             #+#    #+#             */
/*   Updated: 2022/08/31 13:52:17 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
int CheckElement(t_cub *cub)
{
    
    if (cub->map->n == 1)
        if (cub->map->s == 0)
            if (cub->map->e == 0)
                if (cub->map->w == 0)
                    return (DN);
    if (cub->map->n == 0)
        if (cub->map->s == 1)
            if (cub->map->e == 0)
                if (cub->map->w == 0)
                    return (DS);
    if (cub->map->n == 0)
        if (cub->map->s == 0)
            if (cub->map->e == 1)
                if (cub->map->w == 0)
                    return (DE);
    if (cub->map->n == 0)
        if (cub->map->s == 0)
            if (cub->map->e == 0)
                if (cub->map->w == 1)
                    return (DW);
    return (EXIT_FAILURE);
}

void GetDirection(t_cub *cub)
{
    if (cub->map->check == DN)
        cub->map->direction = 'n';
    else if (cub->map->check == DS)
        cub->map->direction = 's';
    else if (cub->map->check == DW)
        cub->map->direction = 'w';
    else if (cub->map->check == DE)
        cub->map->direction = 'e';
}

void  CalculElement(t_cub *cub)
{
    int     i;
    int     j;

    i = 0;
    while (cub->map->TrueMap[i])
    {
        j = 0;
        while (cub->map->TrueMap[i][j])
        {
            if (cub->map->TrueMap[i][j] == 'N')
                cub->map->n++;
            if (cub->map->TrueMap[i][j] == 'S')
                cub->map->s++;
            if (cub->map->TrueMap[i][j] == 'W')
                cub->map->w++;
            if (cub->map->TrueMap[i][j] == 'E')
                cub->map->e++;
            j++;
        }
        i++;
    }
    cub->map->check = CheckElement(cub);
    if (cub->map->check == EXIT_FAILURE)
        err_hand(15);
    GetDirection(cub);
}

void CheckObjects(t_cub *cub)
{
    char    **map;
    int     j;
    int     i;
    
    i = 0;
    map = cub->map->TrueMap;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '1')
                if (map[i][j] != '0')
                    if (map[i][j] != 'N')
                        if (map[i][j] != 'S')
                            if (map[i][j] != 'W')
                                if (map[i][j] != 'E')
                                    if (map[i][j] != ' ')
                                        err_hand(14);
            j++;
        }
        i++;
    }
    CalculElement(cub);
}