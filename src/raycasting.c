/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/11 13:06:20 by izail            ###   ########.fr       */
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

int checkRaysMap(t_cub *cub, double bx, double by)
{
    int x;
    int y;
    int leny;
    int lenx;
    
    x = floor(bx / 30);
    y = floor(by / 30);
    leny = retlen(cub->map->TrueMap);
    if (y < 0 || y > leny)
    {
        printf("222\n");   
        return (EXIT_FAILURE);
    }
    if ((cub->map->TrueMap[y]))
        lenx = ft_strlen(cub->map->TrueMap[y]);
    else
        return (EXIT_FAILURE);
    if (x < 0 || x > lenx)
    {
        printf("ah\n");  
        return (EXIT_FAILURE);
    }
    if (cub->map->TrueMap[y][x] == '1')
    {
        printf("3333\n");   
        return (EXIT_FAILURE);
    }
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
    
    
    by = floor(y0 / 30) * 30;
    if (rd >= 0 && rd <= M_PI)
        by += 30;
    bx = (by - y0) / tan(rd) + x0;
    ystep = 30;
    if (is_facing_up)
        ystep *= -1;
    xstep = ystep / tan(rd);
    // printf("x stp == %f\n", xstep);
    // if (is_facing_right && xstep < 0)
    //     xstep *= -1;
    // if (is_facing_left && xstep > 0)
    //     xstep *= -1;
    while (1)
    {
        if (checkRaysMap(cub, bx,by) == EXIT_FAILURE)
            break;
        // if (cub->map->TrueMap[(int)(by/ 30)][(int)(bx / 30)] == '1')
        //     return (EXIT_SUCCESS);
        by += ystep;
        bx += xstep;
    }
    // DDA(cub, x0, y0, bx, by  , 0x087f5b);
    // printf("xh == %f  yh == %f\n", bx, by);
    // cub->hv.xh = bx;
    // cub->hv.yh = by;
    // printf("x %f\n", bx);
    // printf("y %f\n", by);
    return (EXIT_SUCCESS);
}

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
    
    bx = floor(x0 / 30) * 30;
    if (is_facing_right)
        bx += 30;
    by = y0 + (tan(rd) * (bx - x0));
    xstep = 30;
    // printf("rd _v == %f\n", rd);
    if (is_facing_left)
        xstep *= -1;
    ystep = xstep * tan(rd);
    if (is_facing_up && (ystep > 0))
        ystep *= -1;
    if (is_facing_down && (ystep < 0))
        ystep *= -1;

    
    printf("ystep == %f\n", ystep);
    printf("xstep %f\n", xstep);
    
        
    while (1)
    {
        // printf("11\n");
         
        if (checkRaysMap(cub, bx,by) == EXIT_FAILURE)
            break;
        // if (cub->map->TrueMap[(int)(by/ 30)][(int)(bx / 30)] == '1')
        //     return (EXIT_SUCCESS);
        bx += xstep;
        by += ystep;
    }
    DDA(cub, x0, y0, bx, by, 0x087f9b);
    return (EXIT_SUCCESS);
}
        
void checkWall (t_cub *cub,double x0, double y0, double rd)
{
    
    
    stepHorizontale(cub,rd,x0, y0);
    printf("00\n");
    stepvertical(cub, rd, x0, y0);
    
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
        x1 = x0  + cos(rd) * 100;
        y1 = y0  + sin(rd) * 100;
        DDA(cub, x0, y0, x1, y1, 0xe3e305);
        checkWall(cub,x0, y0, rd); 
        // rayc(cub, x0 , y0, rd);
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
    while (1)
    {
        if (cub->map->TrueMap[(int)(By/ 30)][(int)(Bx/ 30)] == '1')
            break;
        printf("11\n");
        Bx += cub->stepx;
        By += cub->stepy;
    }
    
    
}