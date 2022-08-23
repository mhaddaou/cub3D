/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializeWindow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 06:50:30 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/23 12:36:37 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    initializeWindow(t_cub *cub)
{
    cub->player.playerX = 0;
    cub->player.playerY = 0;
    void *img_all;
    
    img_all = "./img/blue.xpm";
    t_data img;
    cub->mlx = mlx_init();
    cub->win = mlx_new_window(cub->mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "cub3D");
    // cub->img= mlx_xpm_file_to_image(cub->mlx, img_all, &cub->img_width, &cub->img_height );
    int x, y;
    x = 0;
    y = 0;
    img.img = mlx_new_image(cub->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
    // mlx_loop_hook(cub->mlx, &render, &cub);
	mlx_loop(cub->mlx);
    // mlx_pixel_put(cub->mlx, cub->win, 15, 20, 255);
}