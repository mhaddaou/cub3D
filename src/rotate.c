/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:15:38 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/05 21:33:34 by mhaddaou         ###   ########.fr       */
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

void DDA(t_cub *cub, int X0, int Y0, int X1, int Y1)
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
        my_mlx_pixel_put (&cub->data, round(X),round(Y),0xff0200);
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
    rd = cub->player.rotate - 5;
    rf = cub->player.rotate + 5;
    x0 = cub->player.x * 30 + 5;
    y0 = cub->player.y * 30 + 5;
    while (rd < rf)
    {
        x1 = x0  + cos(rd) * 30;
        y1 = y0  + sin(rd) * 30;
        DDA(cub, x0, y0, x1, y1);
        rd += 0.2;
        
    }
    
    
}