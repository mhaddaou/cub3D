/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:31:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 18:20:53 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	init_color(t_map *map)
{
	map->f_c.r = 0;
	map->f_c.g = 0;
	map->f_c.b = 0;
	map->c_c.r = 0;
	map->c_c.g = 0;
	map->c_c.b = 0;
}

void	init_side(t_cub *cub)
{
	cub->map->e = 0;
	cub->map->w = 0;
	cub->map->n = 0;
	cub->map->s = 0;
}

void	init(t_map *map)
{
	int	i;

	i = 0;
	map->n_texture = NULL;
	map->e_texture = NULL;
	map->w_texture = NULL;
	map->s_texture = NULL;
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
	init_color(map);
	ft_bzero(map->number, 10);
}
