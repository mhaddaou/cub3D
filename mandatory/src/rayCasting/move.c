/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:19:35 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/27 11:17:55 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"


void moveRight (t_cub *cub)
{
    
    cub->player.x += 0.2;
    if (checkWallR(cub) == EXIT_FAILURE)
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
    if (checkWallU(cub) == EXIT_FAILURE)
    {
       cub->player.y += 0.2;
       return ;
    }
    else
        printAll(cub);
}
void moveDown (t_cub *cub)
{
    cub->player.y += 0.2;
    if (checkWallD(cub) == EXIT_FAILURE)
    {
        cub->player.y -= 0.2;
        return ;
    }
    else
        printAll(cub);
}

