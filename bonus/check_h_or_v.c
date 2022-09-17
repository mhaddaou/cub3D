/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h_or_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:08:19 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	check_h_or_v(t_cub *cub, char c)
{
	if (c == 'h')
	{
		cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data4.width;
	}
	else
	{
		cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data4.width;
	}
}
