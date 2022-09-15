/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 18:43:52 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	retlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	convert_3d(t_cub *cub, double distray, double rd)
{
	int	y;
	int	dist;

	cub->dist_project_plane
		= (TILE_SIZE / 2) / tan((cub->fov / 2) * (M_PI / 180));
	distray = distray * cos(rd - cub->player.rotate);
	cub->wall_height = (TILE_SIZE / distray)
		* cub->dist_project_plane * TILE_SIZE;
	if (cub->wall_height > cub->ry)
		cub->wall_height = cub->ry;
	if (cub->wall_height < 0)
		cub->wall_height = 0;
}
