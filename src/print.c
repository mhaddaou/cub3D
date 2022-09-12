/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:13:36 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/12 19:10:31 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    
	char	*dst;

    if (x < 0 || x > 1080)
        return;
    if (y < 0 || y > 1080)
        return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void printMap(t_cub *cub,int x, int y, int color)
{
    int x1;
    x1 = x;
     while (y < cub->y )
     {
         x = x1;
         while (x < cub->x )
         {
             my_mlx_pixel_put(&cub->data, x, y, color);
             x++;
         }
         y++;
     }
}

void CheckPrintTrueMap(t_cub *cub)
{
    int x;
    int y;
    int i;
    int j;
    
    y = 0;
    while (cub->map->TrueMap[y])
    {
        x = 0;
        while (cub->map->TrueMap[y][x])
        {
            if (cub->map->TrueMap[y][x] == '1')
            {
                i = y * 30;
                j = x * 30;
                cub->x = j + 30;
                cub->y = i + 30;
                printMap(cub, j, i, 0x8a2be2);
            }
            if (cub->map->TrueMap[y][x] == '0')
            {
                i = y * 30;
                j = x * 30;
                cub->x = j + 30;
                cub->y = i + 30;
                printMap(cub, j, i, 0xf5f9ff);
            }
            x++;
            
        }
        y++;
    }    
}
unsigned long createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}


int update (t_cub *cub)
{
    unsigned long clr = createRGB(cub->map->C.R, cub->map->C.G, cub->map->C.B);
    // ddaALGO(cub);
    int y = cub->ry / 2;
    int i = 0;
    int j;
    while (i  < y)
    {
        j = 0;
        while (j < cub->rx)
        {
            my_mlx_pixel_put(&cub->data,j, i, clr);
            j++;
        }
        i++;
    }
    
    while (i < cub->ry)
    {
        j = 0;
        while (j < cub->rx)
        {
            my_mlx_pixel_put(&cub->data,j, i, 0x2201000);
            j++;    
        }
        i++;
    }
    FieldOfView(cub);
    mlx_put_image_to_window(cub->mlx, cub->win,cub->data.img ,0, 0 );
    return (0);
}

