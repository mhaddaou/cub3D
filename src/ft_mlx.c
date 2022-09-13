/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:13:33 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/13 22:05:32 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    InitRotate(t_cub *cub)
{
    if (cub->map->direction == 'n')
        cub->player.rotate =( 1.5 * M_PI);
    if (cub->map->direction == 's')
        cub->player.rotate =( M_PI / 2);
    if (cub->map->direction == 'w')
        cub->player.rotate = M_PI;
    if (cub->map->direction == 'e')
        cub->player.rotate = 0;
}

void ft_iniit(t_cub *cub)
{
    cub->rx = 1080;
    cub->ry = 1080;
    cub->fov = 60 ;
    cub->player.x = cub->map->posX + 0.3;
    cub->player.y = cub->map->posY  +0.5  ;
    InitRotate(cub);
    cub->x = 0;
    cub->y = 0;
    cub->key.a = 0;
    cub->key.d = 0;
    cub->key.w = 0;
    cub->key.s = 0;
    cub->key.rl = 0;
    cub->key.rr = 0;
}

int mouve(t_cub *cub)
{
    if (cub->key.a == 1)
        mouveLeft(cub);
    if (cub->key.d == 1)
        mouveRight(cub);
    if (cub->key.w == 1)
        mouveUp(cub);
    if (cub->key.s == 1)
        mouveDown(cub);
    if (cub->key.rl == 1)
        RotateLeft(cub);
    if (cub->key.rr == 1)
        RotateRight(cub);
    return (EXIT_SUCCESS);
}
int checkMV(int key, t_cub *cub)
{
    if (key == A)
        cub->key.a = 1;
    if (key == D)
        cub->key.d = 1;
    if (key == W)
        cub->key.w = 1;
    if (key == S)
        cub->key.s = 1;
    if (key == ESC)
        exit(0);
    if (key == LFT)
        cub->key.rl = 1;
    if (key == RGT)
        cub->key.rr = 1;
    return (EXIT_SUCCESS);
    
}
int checkMV2(int key, t_cub *cub)
{
    if (key == A)
        cub->key.a = 0;
    if (key == D)
        cub->key.d = 0;
    if (key == W)
        cub->key.w = 0;
    if (key == S)
        cub->key.s = 0;
    if (key == ESC)
        exit(0);
    if (key == LFT)
        cub->key.rl = 0;
    if (key == RGT)
        cub->key.rr = 0;
    return (EXIT_SUCCESS);
    
}


void ft_mlx(t_cub *cub)
{
    ft_iniit(cub);
    cub->mlx = mlx_init();
    cub->win = mlx_new_window(cub->mlx, cub->rx, cub->ry, "mhaddaou && izail");
	cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img, &cub->data.bits_per_pixel, &cub->data.line_length,
								&cub->data.endian);
    update(cub);
    // mlx_loop_hook(cub->mlx, &update, cub);
    // mlx_key_hook(cub->win, &mouve, cub);
    mlx_hook(cub->win, 2, 0, &checkMV, cub);
    mlx_hook(cub->win, 3, 0, &checkMV2, cub);
    mlx_loop_hook(cub->mlx, &mouve, cub);
    // mlx_clear_window(cub->mlx, cub->win);
    
    mlx_loop(cub->mlx);
    
}

