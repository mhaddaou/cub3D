/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/17 22:46:21 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	cub->dist_project_plane
		= (TILE_SIZE / 2) / tan((cub->fov / 2) * (M_PI / 180));
	distray = distray * cos(rd - cub->player.rotate);
	cub->wall_height = (TILE_SIZE / distray)
		* cub->dist_project_plane * TILE_SIZE;
}
