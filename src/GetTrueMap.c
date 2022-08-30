/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetTrueMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:55:47 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/30 16:02:36 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void GoToC(t_map *map, int i, int j)
{
    int x;

    x = 0;
    while (i < j)
    {
        map->TrueMap[x] = ft_strdup(map->map[i]);
        i++;
        x++;
    }
    map->TrueMap[x] = NULL;
}

void InitializeTrueMap(t_cub *cub, int i, int j)
{
    int len;
    len = (j - i) + 1;
    cub->map->TrueMap = (char **) malloc (sizeof(char *) *(len));
    if (!cub->map->TrueMap)
        err_hand(1);
    GoToC(cub->map, i, j);
}

void GetTrueMap(t_cub *cub)
{
    int i;
    int j;
    
    i = cub->map->check;
    // printf("i == %d\n", i);
    while (!ft_strncmp(cub->map->map[i],"\n", ft_strlen(cub->map->map[i])))
        i++;
    j = i ;
    while (cub->map->map[j])
        j++;
 
    InitializeTrueMap(cub, i, j);
}