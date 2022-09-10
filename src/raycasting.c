/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/09 21:24:28 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void steps(t_cub *cub, double rd, double x, double y)
{
    double xstep;
    double ystep;
    int x0 = x;
    int y0 = y;
    
    if (cub->check == 'v')
    {
        xstep = 30;
        ystep = xstep * tan(rd);
        while (1)
        {
            if (cub->map->TrueMap[(int)(y/ 30)][(int)(x / 30)] == '1')
                break;   
            y -= ystep;
            x -= xstep;
        }
        DDA(cub, x0, y0, x, y, 0x087f5b);
    }
    
    
}
        
void checkWall (t_cub *cub,double x0, double y0, double rd)
{
    double by, bx;
    // by= floor(y0 / 30) * 30;
    // if (rd >= 0 && rd <= M_PI)
    //     by += 30;
    // double bx   = (by - y0) / tan(rd) + x0;
    // cub->check = 'h';
    // steps(cub,rd,bx, by);
    bx = floor(x0 / 30) * 30;
    if (rd >= 1.5 * M_PI || rd <= M_PI / 2)
        bx += 30;
    by = y0 + (tan(rd) * (bx - x0));
    cub->check = 'v';    
    steps(cub,rd,bx, by);
}


void FieldOfView(t_cub *cub)
{
    

    double rd = cub->player.rotate - ((cub->fov * (M_PI / 180)) / 2);
    
    double fov_inc = cub->fov * (M_PI / 180)  / cub->rx;
    double x0 = cub->player.x * 30 + 5;
    double y0 = cub->player.y * 30 + 5;
    double x1,y1;
    int i = 0;
    while (i  < cub->rx)
    {
        rd = fmod(rd, 2 * M_PI);
        if (rd < 0)
            rd += 2 * M_PI;
        x1 = x0  + cos(rd) * 200;
        y1 = y0  + sin(rd) * 200;
        DDA(cub, x0, y0, x1, y1, 0xe3e305);
        checkWall(cub,x0, y0, rd); 
        rd += fov_inc;
        break;
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