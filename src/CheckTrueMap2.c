/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:19:16 by izail             #+#    #+#             */
/*   Updated: 2022/08/31 11:47:16 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
void CheckElement(t_cub *cub)
{
    if (cub->map->n != 0 && cub->map->n != 1)
        if (cub->map->s != 0 && cub->map->s != 1)
            if (cub->map->w != 0 && cub->map->w != 1)
                if (cub->map->e != 0 && cub->map->e != 1)
                    err_hand(15);
    
    
}
void  CalculElement(t_cub *cub)
{
    char    **map;
    int     i;
    int     j;

    i = 0;
    map = cub->map->TrueMap;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N')
                cub->map->n++;
            if (map[i][j] == 'S')
                cub->map->s++;
            if (map[i][j] == 'W')
                cub->map->w++;
            if (map[i][j] == 'E')
                cub->map->e++;
            j++;
        }
        i++;
    }
    printf("nn == %d\n", cub->map->n);
    CheckElement(cub);
    
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