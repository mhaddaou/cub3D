/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:49:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 15:23:01 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	position_player(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	cub->player.x = 0;
	cub->player.y = 0;
	while (y < cub->map->map_height)
	{
		x = 0;
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] == 'P')
			{
				cub->player.x = x;
				cub->player.y = y;
			}
			x++;
		}
		y++;
	}
}
