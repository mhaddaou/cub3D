/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:33:08 by izail             #+#    #+#             */
/*   Updated: 2022/09/14 18:16:44 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	mlx_put_image_to_window(cub->mlx, cub->win, cub->data.img, 0, 0);
	return (0);
}
