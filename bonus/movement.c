/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:09:43 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 18:20:53 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	move_left(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->data.img);
	cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img,
			&cub->data.bits_per_pixel, &cub->data.line_length,
			&cub->data.endian);
	cub->player.x += sin (cub->player.rotate) * 0.1;
	cub->player.y -= cos (cub->player.rotate) * 0.1;
	if (cub->map->truemap[(int)cub->player.y][(int)cub->player.x] == '1'
		|| cub->map->truemap[(int)cub->player.y][(int)cub->player.x] == '\0')
	{
		cub->player.x -= sin(cub->player.rotate) * 0.1;
		cub->player.y += cos(cub->player.rotate) * 0.1;
		return ;
	}
	update(cub);
}

void	move_right(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->data.img);
	cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img,
			&cub->data.bits_per_pixel, &cub->data.line_length,
			&cub->data.endian);
	cub->player.x -= sin(cub->player.rotate) * 0.1;
	cub->player.y += cos(cub->player.rotate) * 0.1;
	if (cub->map->truemap[(int)cub->player.y][(int)cub->player.x] == '1'
		|| cub->map->truemap[(int)cub->player.y][(int)cub->player.x] == '\0')
	{
		cub->player.x += sin (cub->player.rotate) * 0.1;
		cub->player.y -= cos(cub->player.rotate) * 0.1;
		return ;
	}
	update(cub);
}

void	move_up(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->data.img);
	cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img,
			&cub->data.bits_per_pixel, &cub->data.line_length,
			&cub->data.endian);
	cub->player.x += cos(cub->player.rotate) * 0.1;
	cub->player.y += sin(cub->player.rotate) * 0.1;
	if (cub->map->truemap[(int)cub->player.y][(int)cub->player.x] == '1'
		|| cub->map->truemap[(int)cub->player.y][(int)cub->player.x] == '\0')
	{
		cub->player.x -= cos (cub->player.rotate) * 0.1;
		cub->player.y -= sin(cub->player.rotate) * 0.1;
		return ;
	}
	update(cub);
}

void	move_down(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->data.img);
	cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img,
			&cub->data.bits_per_pixel, &cub->data.line_length,
			&cub->data.endian);
	cub->player.x -= cos(cub->player.rotate) * 0.1;
	cub->player.y -= sin(cub->player.rotate) * 0.1;
	if (cub->map->truemap[(int)cub->player.y][(int)cub->player.x] == '1'
		|| cub->map->truemap[(int)cub->player.y][(int)cub->player.x] == '\0')
	{
		cub->player.x += cos (cub->player.rotate) * 0.1;
		cub->player.y += sin(cub->player.rotate) * 0.1;
		return ;
	}
	update(cub);
}
