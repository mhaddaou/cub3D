/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/13 22:50:49 by mhaddaou         ###   ########.fr       */
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
     
    //  printf("bx == %f  by == %f\n", bx,by);
    //  printf("bx == %f  by == %f\n", bx / TILE_SIZE,by/TILE_SIZE);
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
    // DDA(cub, x0, y0, bx, by, 0xe3eTILE_SIZE5);
    return (EXIT_SUCCESS);
}
int get_clr(t_cub *cub)
{
        
    return (cub->data2->addr[cub->l]);
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
            clr = get_clr(cub);
            my_mlx_pixel_put (&cub->data , (x + j), (y + i), clr);
            j++;
            cub->l++;
        }
        j = 0;
        i++;
    }
}

double getX (t_cub *cub,int x1,  char c)
{
    double x;
    if (c == 'h')
    {
        x = (cub->hv.x / TILE_SIZE ) ;
        x = (x - (int)x);
    }
    if (c == 'v')
    {
        x = (cub->hv.y / TILE_SIZE ) ;
        x = (x - (int)x);
    }
    x *= cub->data2->width ;
   
   return (x); 
    
}
int ret_color(t_cub *cub, int x)
{
    if (!cub->data2->addr[x])
        return 0;
    printf("x == %d\n", x);
    return (cub->data2->addr[x]);
}
// void drawtex(t_cub *cub, double wallHeight, double y, int x)
// {
//     // int y_tex;

//     //  while (y < wallHeight)
//     // {
//     //     y_tex = y * (cub->data2->height / wallHeight);
//     //     int clr = ret_color(cub, y_tex * cub->data2->width + cub->xt);
        
//     //     my_mlx_pixel_put (&cub->data , x, y, 0xFFFFFF);
        
//     //     y++;
//     // }
    
//     int i;
//     int j;
//     int clr;

//     i = 0;
//     j = 0;
//     clr = 0;
//     while (i < wallHeight)
//     {
//         while (j < 1)
//         {
//             int y_tex = (y + i) * (cub->data2->height / wallHeight);
//             clr = ret_color(cub, y_tex * cub->data2->width + cub->xt); 
//             my_mlx_pixel_put (&cub->data , (x + j), (y + i), clr);
//             j++;
//         }
//         j = 0;
//         i++;
//     }
    
// }


void Convert3D(t_cub *cub, double distray, double rd, int column_id, char c)
{
    double distProjectPlane;
    double wallHeight;
    double x_offset;
    double y_offset;
    int y;
    int end;
    int start;
    int dist;
    double wall;

    distProjectPlane = (TILE_SIZE / 2) / tan((cub->fov / 2) * (M_PI / 180));
    distray = distray * cos(rd  - cub->player.rotate);
    wallHeight = (TILE_SIZE / distray) * distProjectPlane * TILE_SIZE;
    wall = wallHeight;
    if (wallHeight > cub->ry)
        wallHeight = cub->ry;
    if (wallHeight < 0)
        wallHeight = 0;
    if (c == 'h')
    {
        x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x/TILE_SIZE);
        x_offset = x_offset * cub->data2->width;
    }
    else
    {
        x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
        x_offset = x_offset * cub->data2->width;
    }
    start = (cub->ry / 2) - (wallHeight / 2);
    end = (cub->ry / 2) + (wallHeight / 2);
    y = start;
    while (y < end)
    {
        dist = y + (wallHeight / 2) - (cub->ry / 2);
        y_offset = dist * ((float)(cub->data2->height) / wallHeight); 
        // printf (" %d x_offset===%f , y_offset===%f\n",i,x_offset,(y_offset * cub->data2->width));
        // printf("111\n");
        // int t = cub->data.addr[1168387];
        // printf("222\n");
        cub->data.addr[y * cub->rx + column_id] = cub->data2->addr[(int)(y_offset) * (cub->data2->width) + (int)x_offset];
        // i++;
        y++;
    }
    // draw_column(column_id, (cub->rx / 2) - (wallHeight / 2), 0x862e9c, cub, wallHeight);
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
        Convert3D(cub, dh, rd, i, 'h');
    }
    else
    {
        cub->hv.x = cub->hv.xv;
        cub->hv.y = cub->hv.yv;
        Convert3D(cub, dv, rd, i, 'v');
    }
    
}
void calculDistancemini(t_cub *cub, double x0, double y0, double rd, int i)
{
    double dv;
    double dh;

    dv = sqrt((pow(cub->hv.xv - x0, 2) + pow(cub->hv.yv - y0, 2)));
    dh = sqrt((pow(cub->hv.xh - x0, 2) + pow(cub->hv.yh - y0, 2)));
    if (dv > dh)
    {
        cub->hv.x = cub->hv.xh;
        cub->hv.y = cub->hv.yh;
        // Convert3D(cub, dh, rd, i, 'h');
    }
    else
    {
        cub->hv.x = cub->hv.xv;
        cub->hv.y = cub->hv.yv;
        // Convert3D(cub, dv, rd, i, 'v');
    }
    
}
 
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

int getlen(t_cub *cub)
{
    long i = 0;
    while (cub->data2->addr[i])
        i++;
    return (i);
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
    long len = getlen(cub);
    // printf("len == %ld\n", len);
    while (i  < cub->rx)
    {
        // printf("hello\n");
        rd = fmod(rd, 2 * M_PI);
        if (rd < 0)
            rd += 2 * M_PI;
        x1 = x0  + cos(rd) * 100;
        y1 = y0  + sin(rd) * 100;
        // DDA(cub, x0, y0, x1, y1, 0xe3eTILE_SIZE5);
        checkWall(cub,x0, y0, rd, i);
        
        // DDA(cub, x0/3, y0/3, cub->hv.x/3, cub->hv.y/3,0xbac8ff);
        
        rd += fov_inc;
        // if (i == 2)
        //     break;
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
    long len = getlen(cub);
    // printf("len == %ld\n", len);
    while (i  < cub->rx)
    {
        // printf("hello\n");
        rd = fmod(rd, 2 * M_PI);
        if (rd < 0)
            rd += 2 * M_PI;
        x1 = x0  + cos(rd) * 100;
        y1 = y0  + sin(rd) * 100;
        // DDA(cub, x0, y0, x1, y1, 0xe3eTILE_SIZE5);
        checkWallmini(cub,x0, y0, rd, i);
        
        DDA(cub, x0/3, y0/3, cub->hv.x/3, cub->hv.y/3,0xbac8ff);
        
        rd += fov_inc;
        // if (i == 2)
        //     break;
        i++;
    }
}

// void raycasting(t_cub *cub)
// {
//     printf("dkhel\n");
//     double By, Bx , Px, Py;
    
//     Px =(cub->player.x + 0.5) * TILE_SIZE;
//     Py = (cub->player.y + 0.5) * TILE_SIZE;
//     printf("%f\n", Px);
//     printf("%f\n", Py);
//     By = (int)(Py / TILE_SIZE) * TILE_SIZE;
//     printf("by == %f\n", By);
//     printf("tan %f\n", (cub->player.rotate));
//     Bx = Px + ((By - Py) / tan(cub->player.rotate));
    
//     printf("bx == %f\n", Bx);
    
//     cub->stepy = TILE_SIZE;
//     cub->stepx = cub->stepy / tan(cub->player.rotate);
//     while (1)
//     {
//         if (cub->map->TrueMap[(int)(By/ TILE_SIZE)][(int)(Bx/ TILE_SIZE)] == '1')
//             break;
//         printf("11\n");
//         Bx += cub->stepx;
//         By += cub->stepy;
//     }
    
    
// }