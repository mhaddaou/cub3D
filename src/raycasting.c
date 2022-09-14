/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 06:51:33 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int retlen(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}
void drawTexture(t_cub *cub, char c, int column_id, int order)
{
    int dist;
    int y;
    if (order == 4)
    {
        if (c == 'h')
        {
            cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x/TILE_SIZE);
            cub->x_offset = cub->x_offset * cub->data4.width;
        }
        else
        {
            cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
            cub->x_offset = cub->x_offset * cub->data4.width;
        }
        cub->start = (cub->ry / 2) - (cub->wallHeight / 2);
        cub->end = (cub->ry / 2) + (cub->wallHeight / 2);
        y = cub->start;
        while (y < cub->end)
        {
            dist = y + (cub->wallHeight / 2) - (cub->ry / 2);
            cub->y_offset = dist * ((float)(cub->data4.height) / cub->wallHeight); 
            cub->data.addr[y * cub->rx + column_id] = cub->data4.addr[(int)(cub->y_offset) * (cub->data4.width) + (int)cub->x_offset];
            y++;
        }
    }
    else if (order == 1)
    {
        if (c == 'h')
        {
            cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x/TILE_SIZE);
            cub->x_offset = cub->x_offset * cub->data1.width;
        }
        else
        {
            cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
            cub->x_offset = cub->x_offset * cub->data1.width;
        }
        cub->start = (cub->ry / 2) - (cub->wallHeight / 2);
        cub->end = (cub->ry / 2) + (cub->wallHeight / 2);
        y = cub->start;
        while (y < cub->end)
        {
            dist = y + (cub->wallHeight / 2) - (cub->ry / 2);
            cub->y_offset = dist * ((float)(cub->data1.height) / cub->wallHeight); 
            cub->data.addr[y * cub->rx + column_id] = cub->data1.addr[(int)(cub->y_offset) * (cub->data1.width) + (int)cub->x_offset];
            y++;
        }
    }
    else if (order == 2)
    {
        if (c == 'h')
        {
            cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x/TILE_SIZE);
            cub->x_offset = cub->x_offset * cub->data2.width;
        }
        else
        {
            cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
            cub->x_offset = cub->x_offset * cub->data2.width;
        }
        cub->start = (cub->ry / 2) - (cub->wallHeight / 2);
        cub->end = (cub->ry / 2) + (cub->wallHeight / 2);
        y = cub->start;
        while (y < cub->end)
        {
            dist = y + (cub->wallHeight / 2) - (cub->ry / 2);
            cub->y_offset = dist * ((float)(cub->data2.height) / cub->wallHeight); 
            cub->data.addr[y * cub->rx + column_id] = cub->data2.addr[(int)(cub->y_offset) * (cub->data2.width) + (int)cub->x_offset];
            y++;
        }
    }
     else if (3)
    {
        if (c == 'h')
        {
            cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x/TILE_SIZE);
            cub->x_offset = cub->x_offset * cub->data3.width;
        }
        else
        {
            cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
            cub->x_offset = cub->x_offset * cub->data3.width;
        }
        cub->start = (cub->ry / 2) - (cub->wallHeight / 2);
        cub->end = (cub->ry / 2) + (cub->wallHeight / 2);
        y = cub->start;
        while (y < cub->end)
        {
            dist = y + (cub->wallHeight / 2) - (cub->ry / 2);
            cub->y_offset = dist * ((float)(cub->data3.height) / cub->wallHeight); 
            cub->data.addr[y * cub->rx + column_id] = cub->data3.addr[(int)(cub->y_offset) * (cub->data3.width) + (int)cub->x_offset];
            y++;
        }
    }
    
}


void Convert3D(t_cub *cub, double distray, double rd, int column_id, char c)
{
    // double distProjectPlane;
    // double wallHeight;
    // double x_offset;
    // double y_offset;
    int y;
    // int end;
    // int start;
    int dist;

    cub->distProjectPlane = (TILE_SIZE / 2) / tan((cub->fov / 2) * (M_PI / 180));
    distray = distray * cos(rd  - cub->player.rotate);
    cub->wallHeight = (TILE_SIZE / distray) * cub->distProjectPlane * TILE_SIZE;
    if (cub->wallHeight > cub->ry)
        cub->wallHeight = cub->ry;
    if (cub->wallHeight < 0)
        cub->wallHeight = 0;
    // drawTexture(cub, c, rd, column_id);
    
    // if (c == 'h')
    // {
    //     cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x/TILE_SIZE);
    //     cub->x_offset = cub->x_offset * cub->data4.width;
    // }
    // else
    // {
    //     cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
    //     cub->x_offset = cub->x_offset * cub->data4.width;
    // }
    // cub->start = (cub->ry / 2) - (cub->wallHeight / 2);
    // cub->end = (cub->ry / 2) + (cub->wallHeight / 2);
    // y = cub->start;
    // while (y < cub->end)
    // {
    //     dist = y + (cub->wallHeight / 2) - (cub->ry / 2);
    //     cub->y_offset = dist * ((float)(cub->data4.height) / cub->wallHeight); 
    //     cub->data.addr[y * cub->rx + column_id] = cub->data4.addr[(int)(cub->y_offset) * (cub->data4.width) + (int)cub->x_offset];
    //     y++;
    // }
}


 




