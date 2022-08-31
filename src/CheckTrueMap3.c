/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:55:17 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/31 15:42:22 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


 int CalculeTrueMap(t_cub *cub)
 {
     int i;

     i = 0;
     while (cub->map->TrueMap[i])
        i++;
    return (i);
 }
 
void GetPositionPlayer(t_cub *cub)
{
    int i;
    int j;
    char **map;

    i = 0;
    map = cub->map->TrueMap;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S')
            {
                cub->map->posX = j;
                cub->map->posY = i;
                break;
            }
            j++;
        }
        i++;
    }
    cub->map->TrueMap[cub->map->posY][cub->map->posX] = '0';
}

 int    CheckNoSoEaFC(t_map *map)
{
    if (map->n == 1)
        if (map->s == 1)
            if (map->e == 1)
                if (map->f == 1)
                    if (map->c == 1)
                        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

void CheckInsideMap(t_cub *cub)
{
    int i;
    int j;
    
    i = 0;
    while (i < cub->map_height - 1)
    {
        j = 1;
        printf("%s\n", cub->map->TrueMap[i]);
            while (cub->map->TrueMap[i][j])
            {
                if (cub->map->TrueMap[i + 1][j] == '0')
                {
                    if((cub->map->TrueMap[i + 2][j] == '1' || cub->map->TrueMap[i + 2][j] == '0') &&
                        (cub->map->TrueMap[i][j] == '1' || cub->map->TrueMap[i][j] == '0'))
                        printf("");
                    else
                        err_hand(16);
                }
                j++;  
            }
        i++;
    }
}