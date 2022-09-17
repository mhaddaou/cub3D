/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:28:35 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	check_rays_map(t_cub *cub, double bx, double by)
{
	int	x;
	int	y;
	int	leny;
	int	lenx;

	x = floor(bx / TILE_SIZE);
	y = floor(by / TILE_SIZE);
	leny = retlen(cub->map->truemap);
	if (y < 0 || y > leny)
		return (EXIT_FAILURE);
	if ((cub->map->truemap[y]))
		lenx = ft_strlen(cub->map->truemap[y]);
	else
		return (EXIT_FAILURE);
	if (x < 0 || x > lenx)
		return (EXIT_FAILURE);
	if ((cub->map->truemap[y][x] == '1') || (cub->map->truemap[y][x] == ' '))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
