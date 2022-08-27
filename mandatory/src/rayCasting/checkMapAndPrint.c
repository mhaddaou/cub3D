/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapAndPrint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:23:56 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/27 11:25:09 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void renderMap(t_cub *cub, int x, int y, int color)
{
    int x1;
    x1 = cub->y;
    
    while (cub->x < x)
    {
        cub->y = x1;
        while (cub->y < y )
        {
            my_mlx_pixel_put(&cub->data, cub->y,cub->x, color);
            cub->y++;
        }
        cub->x++;
    }   
}
void giVal(t_cub *cub, int i, int j, int color, int p)
{
    int x, y;
    if (p == 0)
    {
        cub->x = i * 30;
        cub->y = j * 30;
        x = cub->x + 30;
        y = cub->y + 30;    
    }
    renderMap(cub, x , y , color);
    
}

void check_map(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while (cub->map[i])
    {
        j = 0;
        while (cub->map[i][j])
        {
            if (cub->map[i][j] == '1')
                giVal(cub, i, j, WHITE_PIXEL, 0);
            if (cub->map[i][j] == '0')
                giVal(cub, i, j, GREEN_PIXEL, 0);
            j++;
        }
        i++;
    }    
}