/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:09:43 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/13 20:40:10 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void mouveLeft(t_cub *cub)
{
    mlx_destroy_image(cub->mlx, cub->data.img);
    cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length,
								&cub->data.endian); 
    cub->player.x += sin(cub->player.rotate)* 0.2;
    cub->player.y -= cos(cub->player.rotate)* 0.2; 
    if (cub->map->TrueMap[(int)cub->player.y][ (int)cub->player.x] == '1'  || cub->map->TrueMap[(int)cub->player.y][ (int)cub->player.x] == '\0')
    {
        cub->player.x -= sin (cub->player.rotate)* 0.2;
        cub->player.y += cos(cub->player.rotate)* 0.2;
        return ;
    }
    update(cub);
}

void mouveRight(t_cub *cub)
{
    mlx_destroy_image(cub->mlx, cub->data.img);
    cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length,
								&cub->data.endian);
    cub->player.x -= sin(cub->player.rotate)* 0.2;
    cub->player.y += cos(cub->player.rotate)* 0.2;
    if (cub->map->TrueMap[(int)cub->player.y][ (int)cub->player.x] == '1'  || cub->map->TrueMap[(int)cub->player.y][ (int)cub->player.x] == '\0')
    {
        cub->player.x += sin (cub->player.rotate)* 0.2;
        cub->player.y -= cos(cub->player.rotate)* 0.2;
        return ;
    }
    update(cub);
    
}

void mouveUp(t_cub *cub)
{
    mlx_destroy_image(cub->mlx, cub->data.img);
    cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length,
								&cub->data.endian);
    cub->player.x += cos(cub->player.rotate) * 0.2;
    cub->player.y += sin(cub->player.rotate)* 0.2; 
    if (cub->map->TrueMap[(int)cub->player.y][ (int)cub->player.x] == '1' || cub->map->TrueMap[(int)cub->player.y][ (int)cub->player.x]== '\0')
    {
        cub->player.x -= cos (cub->player.rotate)* 0.2;
        cub->player.y -= sin(cub->player.rotate)* 0.2;
        return ;
    }
    update(cub);
    
}

void mouveDown(t_cub *cub)
{
    mlx_destroy_image(cub->mlx, cub->data.img);
    cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length,
								&cub->data.endian);
    cub->player.x -= cos(cub->player.rotate)* 0.2;
    cub->player.y -= sin(cub->player.rotate)* 0.2;
    if (cub->map->TrueMap[(int)cub->player.y][ (int)cub->player.x] == '1'  || cub->map->TrueMap[(int)cub->player.y][ (int)cub->player.x] == '\0')
    {
        cub->player.x += cos (cub->player.rotate)* 0.2;
        cub->player.y += sin(cub->player.rotate)* 0.2;
        return ;
    }
    update(cub);
}