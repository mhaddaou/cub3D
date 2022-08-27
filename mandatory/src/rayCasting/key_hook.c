/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:13:59 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/27 11:14:33 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int key_hook(int key, t_cub *cub)
{
    int x = cub->player.x;
    int y = cub->player.y;
    if (cub->check == 1)
    {
        cub->map[y][x] = '0';
        cub->check = 0;
    }
    printf("%d\n", key);
    if (key == KEY_RIGHT)
    {
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