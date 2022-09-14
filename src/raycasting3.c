/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:32:43 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 05:42:25 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void checkWall (t_cub *cub, double x0, double y0, double rd, int i)
{
    stepHorizontale(cub,rd,x0, y0);
    stepvertical(cub, rd, x0, y0); 
    calculDistance(cub, x0, y0, rd, i);
    
}


void checkWallmini (t_cub *cub, double x0, double y0, double rd, int i)
{
    stepHorizontale(cub,rd,x0, y0);
    stepvertical(cub, rd, x0, y0); 
    calculDistancemini(cub, x0, y0, rd, i);
}
void FieldOfView(t_cub *cub)
{
    double rd = cub->player.rotate - ((cub->fov * (M_PI / 180)) / 2);
    
    double fov_inc = cub->fov * (M_PI / 180)  / cub->rx;
    double x0 = cub->player.x * TILE_SIZE ;
    double y0 = cub->player.y * TILE_SIZE ;
    double x1,y1;
    int i = 0;
    cub->l = 0;
    
    while (i  < cub->rx)
    {
        rd = fmod(rd, 2 * M_PI);
        if (rd < 0)
            rd += 2 * M_PI;
        x1 = x0  + cos(rd) * 100;
        y1 = y0  + sin(rd) * 100;
        checkWall(cub,x0, y0, rd, i);
        
        rd += fov_inc;
        i++;
    }
}
void FieldOfViewmini(t_cub *cub)
{
    double rd = cub->player.rotate - ((cub->fov * (M_PI / 180)) / 2);
    
    double fov_inc = cub->fov * (M_PI / 180)  / cub->rx;
    double x0 = cub->player.x * TILE_SIZE ;
    double y0 = cub->player.y * TILE_SIZE ;
    double x1,y1;
    int i = 0;
    cub->l = 0;
    while (i  < cub->rx)
    {
        rd = fmod(rd, 2 * M_PI);
        if (rd < 0)
            rd += 2 * M_PI;
        x1 = x0  + cos(rd) * 100;
        y1 = y0  + sin(rd) * 100;
        checkWallmini(cub,x0, y0, rd, i);
        
        DDA(cub, x0/3, y0/3, cub->hv.x/3, cub->hv.y/3,0xbac8ff);
        
        rd += fov_inc;
        i++;
    }
}