/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:15:38 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 07:18:48 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void RotateLeft(t_cub *cub)
{
     cub->player.rotate -= 0.041;
        mlx_destroy_image(cub->mlx, cub->data.img);
        cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	    cub->data.addr = (int *)mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length,
								&cub->data.endian);
       update(cub); 
    
}

void RotateRight(t_cub *cub)
{
    cub->player.rotate += 0.041;
        mlx_destroy_image(cub->mlx, cub->data.img);
        cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	    cub->data.addr = (int *)mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length,
								&cub->data.endian);
       update(cub); 
    
}

void DDA(t_cub *cub, int X0, int Y0, int X1, int Y1, int color)
{
    int dx = X1 - X0;
    int dy = Y1 - Y0;
    int i = 0;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
 
    float X = X0;
    float Y = Y0;
    while (i <= steps)
    {
        my_mlx_pixel_put (&cub->data, round(X),round(Y),color);
        X += Xinc;          
        Y += Yinc;
        i++;                  
    }
}