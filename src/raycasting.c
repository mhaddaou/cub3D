/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/12 18:21:29 by mhaddaou         ###   ########.fr       */
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
    {
        ystep *= -1;
        by -= 0.2;
    }
    xstep = ystep / tan(rd);
    if (is_facing_right && xstep < 0)
        xstep *= -1;
    if (is_facing_left && xstep > 0)
        xstep *= -1;

    // bx -= 0.2;
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
     
    //  printf("bx == %f  by == %f\n", bx,by);
    //  printf("bx == %f  by == %f\n", bx / 30,by/30);
    //  printf("%c\n", cub->map->TrueMap[10][24]);
    while (1)
    {
        if (checkRaysMap(cub, bx,by) == EXIT_FAILURE)
            break;
        bx += xstep;
        by += ystep;
    }
    cub->hv.xv = bx;
    cub->hv.yv = by;
    // DDA(cub, x0, y0, bx, by, 0xe3e305);
    return (EXIT_SUCCESS);
}

void draw_column(int x, int y, int color, t_cub *cub, double colHeight)
{
    int i;
    int j;
    int clr;

    i = 0;
    j = 0;
    clr = 0;
    while (i < colHeight)
    {
        while (j < 1)
        {
            clr = color;
            my_mlx_pixel_put (&cub->data , (x + j), (y + i), clr);
            j++;
        }
        j = 0;
        i++;
    }
}

void Convert3D(t_cub *cub, double distray, double rd, int column_id)
{
    double distProjectPlane;
    double wallHeight;

    distProjectPlane = (30 / 2) / tan((cub->fov / 2) * (M_PI / 180));
    distray = distray * cos(rd  - cub->player.rotate);
    wallHeight = (30 / distray) * distProjectPlane * 30;
    draw_column(column_id, (cub->rx / 2) - (wallHeight / 2), 0x862e9c, cub, wallHeight);
}

void calculDistance(t_cub *cub, double x0, double y0, double rd, int i)
{
    double dv;
    double dh;

    dv = sqrt((pow(cub->hv.xv - x0, 2) + pow(cub->hv.yv - y0, 2)));
    dh = sqrt((pow(cub->hv.xh - x0, 2) + pow(cub->hv.yh - y0, 2)));
    if (dv > dh)
    {
        cub->hv.x = cub->hv.xh;
        cub->hv.y = cub->hv.yh;
        Convert3D(cub, dh, rd, i);
    }
    else
    {
        cub->hv.x = cub->hv.xv;
        cub->hv.y = cub->hv.yv;
        Convert3D(cub, dv, rd, i);
    }
    
}
 
void checkWall (t_cub *cub, double x0, double y0, double rd, int i)
{
    stepHorizontale(cub,rd,x0, y0);
    stepvertical(cub, rd, x0, y0); 
    calculDistance(cub, x0, y0, rd, i);
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
        // printf("hello\n");
        rd = fmod(rd, 2 * M_PI);
        if (rd < 0)
            rd += 2 * M_PI;
        x1 = x0  + cos(rd) * 100;
        y1 = y0  + sin(rd) * 100;
        // DDA(cub, x0, y0, x1, y1, 0xe3e305);
        checkWall(cub,x0, y0, rd, i);
        // DDA(cub, x0, y0, cub->hv.x, cub->hv.y,0xbac8ff);
        rd += fov_inc;
        // break;
        i++;
    }
    mlx_put_image_to_window(cub->mlx, cub->win, cub->data.img, 0, 0);
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