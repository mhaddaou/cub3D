/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:15:38 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 18:20:53 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	rotate_left(t_cub *cub)
{
	cub->player.rotate -= 0.041;
	mlx_destroy_image(cub->mlx, cub->data.img);
	cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img,
			&cub->data.bits_per_pixel, &cub->data.line_length,
			&cub->data.endian);
	update(cub);
}

void	rotate_right(t_cub *cub)
{
	cub->player.rotate += 0.041;
	mlx_destroy_image(cub->mlx, cub->data.img);
	cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img,
			&cub->data.bits_per_pixel, &cub->data.line_length,
			&cub->data.endian);
	update(cub);
}

void	dda(t_cub *cub, int x1, int y1)
{
	int		i;
	float	x0;
	float	y0;

	i = 0;
	if (abs(x1 - cub->x0) > abs(y1 - cub->y0))
		cub->stepsdda = abs(x1 - cub->x0);
	else
		cub->stepsdda = abs(y1 - cub->y0);
	cub->x_inc = (x1 - cub->x0) / (float) cub->stepsdda;
	cub->y_inc = (y1 - cub->y0) / (float) cub->stepsdda;
	x0 = cub->x0;
	y0 = cub->y0;
	while (i <= cub->stepsdda)
	{
		my_mlx_pixel_put(&cub->data, round(x0), round(y0), CFOV);
		x0 += cub->x_inc;
		y0 += cub->y_inc;
		i++;
	}
}
