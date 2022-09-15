/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:33:08 by izail             #+#    #+#             */
/*   Updated: 2022/09/14 18:20:53 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (x < 0 || x > 1080)
		return ;
	if (y < 0 || y > 1080)
		return ;
	data->addr[y * 1080 + x] = color;
}

int	update(t_cub *cub)
{
	print_flor_ciel(cub);
	gettexture(cub);
	field_of_view(cub);
	check_print_true_map(cub);
	field_of_view_mini(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data.img, 0, 0);
	return (0);
}

void	print_map(t_cub *cub, int x, int y, int color)
{
	int	x1;

	x1 = x;
	while (y < cub->y)
	{
		x = x1;
		while (x < cub->x)
		{
			my_mlx_pixel_put(&cub->data, x, y, color);
			x++;
		}
		y++;
	}
}

void	check_print_true_map2(t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	if (cub->map->truemap[y][x] == '1')
	{
		i = y * TILE_SIZE / 3;
		j = x * TILE_SIZE / 3;
		cub->x = j + TILE_SIZE / 3;
		cub->y = i + TILE_SIZE / 3;
		print_map(cub, j, i, 0x8a2be2);
	}
	if (cub->map->truemap[y][x] == '0')
	{
		i = y * TILE_SIZE / 3;
		j = x * TILE_SIZE / 3;
		cub->x = j + TILE_SIZE / 3;
		cub->y = i + TILE_SIZE / 3;
		print_map(cub, j, i, 0xf5f9ff);
	}
}

void	check_print_true_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map->truemap[y])
	{
		x = 0;
		while (cub->map->truemap[y][x])
		{
			check_print_true_map2(cub, x, y);
			x++;
		}
		y++;
	}
}
