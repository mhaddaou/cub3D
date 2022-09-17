/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculdistance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:35:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:17:07 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calcul_distance(t_cub *cub, double x0, double y0, double rd)
{
	double	dv;
	double	dh;

	dv = sqrt((pow(cub->hv.xv - x0, 2) + pow(cub->hv.yv - y0, 2)));
	dh = sqrt((pow(cub->hv.xh - x0, 2) + pow(cub->hv.yh - y0, 2)));
	if (dv > dh)
	{
		cub->hv.x = cub->hv.xh;
		cub->hv.y = cub->hv.yh;
		convert_3d(cub, dh, rd);
		if (cub->hv.ysteph > 0)
			draw_texture(cub, 'h', cub->i_ray, 3);
		else if (cub->hv.ysteph < 0)
			draw_texture(cub, 'h', cub->i_ray, 1);
	}
	else
	{
		cub->hv.x = cub->hv.xv;
		cub->hv.y = cub->hv.yv;
		convert_3d(cub, dv, rd);
		if (cub->hv.xstepv > 0)
			draw_texture(cub, 'v', cub->i_ray, 4);
		else if (cub->hv.xstepv < 0)
			draw_texture(cub, 'v', cub->i_ray, 2);
	}
}
