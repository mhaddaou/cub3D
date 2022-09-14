/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculdistance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:35:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 07:01:37 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
        if (cub->hv.ysteph > 0)
            drawTexture(cub, 'h', i, 3);
        else if (cub->hv.ysteph < 0)
            drawTexture(cub, 'h',i,  1);
    }
    else
    {
        cub->hv.x = cub->hv.xv;
        cub->hv.y = cub->hv.yv;
        Convert3D(cub, dv, rd, i, 'v');
        if (cub->hv.xstepv > 0)
            drawTexture(cub, 'v', i, 4);
        else if (cub->hv.xstepv < 0)
            drawTexture(cub, 'v',i, 2);
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
    }
    else
    {
        cub->hv.x = cub->hv.xv;
        cub->hv.y = cub->hv.yv;
    }
    
}