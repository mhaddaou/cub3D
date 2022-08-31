/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:31:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/31 15:35:04 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void initColor(t_map *map)
{
    map->F.R = 0;
    map->F.G = 0;
    map->F.B = 0;
    map->C.R = 0;
    map->C.G = 0;
    map->C.B = 0;
    
}

void InitSide(t_cub *cub)
{
    cub->map->e = 0;
    cub->map->w = 0;
    cub->map->n = 0;
    cub->map->s = 0;
    
    
}
void init(t_map *map)
{
    int i;
    
    i = 0;
    map->Ntexture = NULL;
	map->Etexture = NULL;
	map->Wtexture = NULL;
	map->Stexture = NULL;
    map->e = 0;
    map->w = 0;
    map->n = 0;
    map->s = 0;
    map->f = 0;
    map->c = 0;
    map->check = 0;
    map->number = (char *) malloc(sizeof(char) * 10);
    if (!map->number)
        err_hand(1);
    initColor(map);
    ft_bzero(map->number, 10);
}