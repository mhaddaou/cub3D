/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:19:35 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/26 17:22:33 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void get_value(t_cub *cub)
{
    cub->player.x += 3;
}

void moveRight (t_cub *cub)
{
    
    cub->player.x += 0.2;
    // mlx_clear_window(cub->mlx, cub->win);
    // mlx_destroy_image(cub->mlx, cub->data.img);
    printAllc(cub);
}
void moveLeft (t_cub *cub)
{
    cub->player.x -= 0.2;
    printAll(cub);
}
void moveUp (t_cub *cub)
{
    cub->player.y -= 0.2;
    printAll(cub);
}
void moveDown (t_cub *cub)
{
    cub->player.y += 0.2;
    printAll(cub);
}

int key_hook(int key, t_cub *cub)
{
    int x = cub->player.x;
    int y = cub->player.y;
    cub->map[y][x] = '0';
    if (key == KEY_RIGHT)
    {
        // mlx_clear_window(cub->mlx, cub->win);
        moveRight(cub);
    }
    if (key == KEY_LEFT)
    {
        moveLeft(cub);
    }
    if (key == KEY_UP)
        moveUp(cub);
    if (key == 1)
        moveDown(cub);
    
    
    return (0);
}