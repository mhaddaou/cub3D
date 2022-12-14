/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:32:43 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 18:37:00 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_wall(t_cub *cub, double x0, double y0, double rd)
{
	stephorizontale(cub, rd, x0, y0);
	stepvertical(cub, rd, x0, y0);
	calcul_distance(cub, x0, y0, rd);
}

void	field_of_view(t_cub *cub)
{
	double	rd;
	double	fov_inc;
	double	x0;
	double	y0;

	rd = cub->player.rotate - ((cub->fov * (M_PI / 180)) / 2);
	fov_inc = cub->fov * (M_PI / 180) / cub->rx;
	x0 = cub->player.x * TILE_SIZE;
	y0 = cub->player.y * TILE_SIZE;
	cub->i_ray = 0;
	while (cub->i_ray < cub->rx)
	{
		rd = fmod(rd, 2 * M_PI);
		if (rd < 0)
			rd += 2 * M_PI;
		check_wall(cub, x0, y0, rd);
		rd += fov_inc;
		cub->i_ray++;
	}
}
