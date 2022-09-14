/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:28:35 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 06:14:32 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int stepvertical(t_cub *cub, double rd, double x0, double y0)
{
    double bx;
    double by;
    double xstep;
    double ystep;
    bool is_facing_down = (rd > 0 && rd < M_PI);
    bool is_facing_up = ! is_facing_down;
    bool is_facing_right = (rd > 1.5 * M_PI || rd < M_PI_2);
    bool is_facing_left = !is_facing_right;
    
    bx = floor(x0 / TILE_SIZE) * TILE_SIZE;
    if (is_facing_right)
        bx += TILE_SIZE;
    by = y0 + (tan(rd) * (bx - x0));
    xstep = TILE_SIZE;
    if (is_facing_left)
    {
        xstep *= -1;
        bx -= 0.2; 
    }
    ystep = xstep * tan(rd);
    if (is_facing_up && (ystep > 0))
        ystep *= -1;
    if (is_facing_down && (ystep < 0))
        ystep *= -1;
    cub->hv.xstepv = xstep; 
    while (1)
    {
        if (checkRaysMap(cub, bx,by) == EXIT_FAILURE)
            break;
        bx += xstep;
        by += ystep;
    }
    cub->hv.xv = bx;
    cub->hv.yv = by;
    return (EXIT_SUCCESS);
}

int stepHorizontale(t_cub *cub, double rd, double x0, double y0)
{
    double bx;
    double by;
    double xstep;
    double ystep;
    bool is_facing_down = (rd > 0 && rd < M_PI);
    bool is_facing_up = ! is_facing_down;
    bool is_facing_right = (rd > 1.5 * M_PI || rd < M_PI_2);
    bool is_facing_left = !is_facing_right;
    
    
    by = floor(y0 / TILE_SIZE) * TILE_SIZE;
    if (rd >= 0 && rd <= M_PI)
        by += TILE_SIZE;
    bx = (by - y0) / tan(rd) + x0;
    ystep = TILE_SIZE;
    if (is_facing_up)
    {
        ystep *= -1;
        by -= 0.2;
    }
    xstep = ystep / tan(rd);
    if (is_facing_right && xstep < 0)
        xstep *= -1;
    if (is_facing_left && xstep > 0)
        xstep *= -1;
    cub->hv.ysteph = ystep;
    while (1)
    {
        if (checkRaysMap(cub, bx,by) == EXIT_FAILURE)
            break;
        by += ystep;
        bx += xstep;
    }
    cub->hv.xh = bx;
    cub->hv.yh = by;
    
    return (EXIT_SUCCESS);
}

int checkRaysMap(t_cub *cub, double bx, double by)
{
    int x;
    int y;
    int leny;
    int lenx;
    
    x = floor(bx / TILE_SIZE);
    y = floor(by / TILE_SIZE);
    leny = retlen(cub->map->TrueMap);
    if (y < 0 || y > leny)
        return (EXIT_FAILURE);
    if ((cub->map->TrueMap[y]))
        lenx = ft_strlen(cub->map->TrueMap[y]);
    else
        return (EXIT_FAILURE);
    if (x < 0 || x > lenx)
        return (EXIT_FAILURE);
    if ((cub->map->TrueMap[y][x] == '1') ||  (cub->map->TrueMap[y][x] == ' '))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}