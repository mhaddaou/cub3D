/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:13:36 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/09 11:58:14 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

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

int update (t_cub *cub)
{
    double x,y,j,i;
    x = cub->player.x * 30;
    y = cub->player.y * 30;
    i = y + 5;
    j = x + 10;
    CheckPrintTrueMap(cub);
    // while (y < i)
    // {
    //     x = cub->player.x * 30;
    //     while (x < j)
    //     {
    //         my_mlx_pixel_put(&cub->data, x, y, 1825500);
    //         x++;
    //     }
    //     y++;
    // }
    ddaALGO(cub);
    FieldOfView(cub);
    mlx_put_image_to_window(cub->mlx, cub->win,cub->data.img ,0, 0 );
    return (0);
}

