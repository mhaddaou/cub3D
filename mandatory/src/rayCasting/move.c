/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:19:35 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/26 18:52:39 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"


void moveRight (t_cub *cub)
{
    
    cub->player.x += 0.2;
    if (checkWalls(cub) == EXIT_FAILURE)
    {
        cub->player.x -= 0.2;   
        return ;
    }
    else
        printAllc(cub);
}
void moveLeft (t_cub *cub)
{
    cub->player.x -= 0.2;
    if (checkWalls(cub) == EXIT_FAILURE)
    {
        cub->player.x += 0.2;   
       return ;
    }
    else
        printAll(cub);
}
void moveUp (t_cub *cub)
{
    cub->player.y -= 0.2;
    if (checkWalls(cub) == EXIT_FAILURE)
    {
       cub->player.x += 0.2;
       return ;
    }
    else
        printAll(cub);
}
void moveDown (t_cub *cub)
{
    cub->player.y += 0.2;
    if (checkWalls(cub) == EXIT_FAILURE)
    {
        cub->player.y -= 0.2;
        return ;
    }
    else
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