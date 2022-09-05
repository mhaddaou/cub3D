/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:34:15 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/04 17:16:11 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void FieldOfView(t_cub *cub)
{
    double r = (double)cub->fov / 120;
    
    int index = 0;
    double angle;
    double last = cub->player.rotate + (cub->fov / 2);
    angle = cub->player.rotate - (cub->fov / 2);
    
    // while (angle < last )
    // {
    //     DDA(cub, (cub->player.x * 30 + 5), (cub->player.y * 30 + 5), (int)(angle * 30 + 5), ());
    //     angle += r;
    // }
    
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