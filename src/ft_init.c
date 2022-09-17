/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:07:47 by izail             #+#    #+#             */
/*   Updated: 2022/09/17 22:37:34 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_rotate(t_cub *cub)
{
	if (cub->map->direction == 'n')
		cub->player.rotate = (1.5 * M_PI);
	if (cub->map->direction == 's')
		cub->player.rotate = (M_PI / 2) - 0.001;
	if (cub->map->direction == 'w')
		cub->player.rotate = M_PI;
	if (cub->map->direction == 'e')
		cub->player.rotate = 0;
}

void	ft_iniit(t_cub *cub)
{
	cub->rx = 1080;
	cub->ry = 1080;
	cub->fov = 60 ;
	cub->player.x = cub->map->pos_x + 0.3;
	cub->player.y = cub->map->pos_y + 0.5;
	init_rotate(cub);
	cub->x = 0;
	cub->y = 0;
	cub->key.a = 0;
	cub->key.d = 0;
	cub->key.w = 0;
	cub->key.s = 0;
	cub->key.rl = 0;
	cub->key.rr = 0;
}
