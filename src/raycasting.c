/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/09 12:00:53 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void FieldOfView(t_cub *cub)
{
    

    double rd = cub->player.rotate - ((cub->fov * (M_PI / 180)) / 2);
    rd = fmod(rd, 2 * M_PI);
    if (rd < 0)
        rd += 2 * M_PI;
    double fov_inc = cub->fov * (M_PI / 180)  / cub->rx;
    double x0 = cub->player.x * 30 + 5;
    double y0 = cub->player.y * 30 + 5;
    double x1,y1;
    int i = 0;
    while (i  < cub->rx)
    {
        x1 = x0  + cos(rd) * 200;
        y1 = y0  + sin(rd) * 200;
        
        DDA(cub, x0, y0, x1, y1, 0xe3e305);
        rd += fov_inc;
        i++;
    }
    
}

void raycasting(t_cub *cub)
{
    printf("dkhel\n");
    double By, Bx , Px, Py;
    
    Px =(cub->player.x + 0.5) * 30;
    Py = (cub->player.y + 0.5) * 30;
    printf("%f\n", Px);
    printf("%f\n", Py);
    By = (int)(Py / 30) * 30;
    printf("by == %f\n", By);
    printf("tan %f\n", (cub->player.rotate));
    Bx = Px + ((By - Py) / tan(cub->player.rotate));
    
    printf("bx == %f\n", Bx);
    
    cub->stepy = 30;
    cub->stepx = cub->stepy / tan(cub->player.rotate);
    // printf("x == %d\n", x);
    // printf("y == %d\n", y);
    
    // printf("heh\n");
    while (1)
    {
        if (cub->map->TrueMap[(int)(By/ 30)][(int)(Bx/ 30)] == '1')
            break;
        printf("11\n");
        Bx += cub->stepx;
        By += cub->stepy;
    }
    printf("nice\n");
    
    
}