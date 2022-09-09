/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:15:38 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/09 11:32:04 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void RotateLeft(t_cub *cub)
{
     cub->player.rotate -= 0.1;
        mlx_destroy_image(cub->mlx, cub->data.img);
        cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	    cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length,
								&cub->data.endian);
       update(cub); 
    
}

void RotateRight(t_cub *cub)
{
    cub->player.rotate += 0.1;
        mlx_destroy_image(cub->mlx, cub->data.img);
        cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	    cub->data.addr = mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length,
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

void ddaALGO(t_cub *cub)
{
    double x0;
    double y0;
    double x1;
    double y1;
    double rd;
    double rf;
    // printf("%d\n", cub->fov);
    // exit(0);
    int i = 0;
    // rd = cub->player.rotate - (cub->fov  / 2);
    x0 = cub->player.x * 30 + 5;
    y0 = cub->player.y * 30 + 5;
    x1 = x0  + cos(cub->player.rotate) * 60;
    y1 = y0  + sin(cub->player.rotate) * 60;
    DDA(cub, x0, y0, x1, y1, 0xf5b942);
        // rd += (cub->fov / cub->rx);
        // i++;
    // }
    
    
}