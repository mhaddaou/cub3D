/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:41:41 by izail             #+#    #+#             */
/*   Updated: 2022/09/14 16:42:39 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	is_facing(t_cub *cub, double rd)
{
	cub->facing.is_facing_down = (rd > 0 && rd < M_PI);
	cub->facing.is_facing_up = ! cub->facing.is_facing_down;
	cub->facing.is_facing_right = (rd > 1.5 * M_PI || rd < M_PI_2);
	cub->facing.is_facing_left = !cub->facing.is_facing_right;
}

void	check_facing_v(t_cub *cub, double *xstep, double *ystep, double rd)
{
	is_facing(cub, rd);
	if (cub->facing.is_facing_left)
	{
		*xstep *= -1;
		cub->_bxy._bx -= 0.2;
	}
	*ystep = *xstep * tan(rd);
	if (cub->facing.is_facing_up && (*ystep > 0))
		*ystep *= -1;
	if (cub->facing.is_facing_down && (*ystep < 0))
		*ystep *= -1;
}

int	stepvertical(t_cub *cub, double rd, double x0, double y0)
{
	double	bx;
	double	by;
	double	xstep;
	double	ystep;

	is_facing(cub, rd);
	bx = floor(x0 / TILE_SIZE) * TILE_SIZE;
	if (cub->facing.is_facing_right)
		bx += TILE_SIZE;
	by = y0 + (tan(rd) * (bx - x0));
	xstep = TILE_SIZE;
	cub->_bxy._bx = bx;
	check_facing_v(cub, &xstep, &ystep, rd);
	bx = cub->_bxy._bx;
	cub->hv.xstepv = xstep;
	while (1)
	{
		if (check_rays_map(cub, bx, by) == EXIT_FAILURE)
			break ;
		bx += xstep;
		by += ystep;
	}
	cub->hv.xv = bx;
	cub->hv.yv = by;
	return (EXIT_SUCCESS);
}

void	check_facing_h(t_cub *cub, double *xstep, double *ystep, double rd)
{
	is_facing(cub, rd);
	if (cub->facing.is_facing_up)
	{
		*ystep *= -1;
		cub->_bxy._by -= 0.2;
	}
	*xstep = *ystep / tan(rd);
	if (cub->facing.is_facing_right && *xstep < 0)
		*xstep *= -1;
	if (cub->facing.is_facing_left && *xstep > 0)
		*xstep *= -1;
}

int	stephorizontale(t_cub *cub, double rd, double x0, double y0)
{
	double	bx;
	double	by;
	double	xstep;
	double	ystep;

	is_facing(cub, rd);
	by = floor(y0 / TILE_SIZE) * TILE_SIZE;
	if (rd >= 0 && rd <= M_PI)
		by += TILE_SIZE;
	bx = (by - y0) / tan(rd) + x0;
	ystep = TILE_SIZE;
	cub->_bxy._by = by;
	check_facing_h(cub, &xstep, &ystep, rd);
	by = cub->_bxy._by;
	cub->hv.ysteph = ystep;
	while (1)
	{
		if (check_rays_map(cub, bx, by) == EXIT_FAILURE)
			break ;
		by += ystep;
		bx += xstep;
	}
	cub->hv.xh = bx;
	cub->hv.yh = by;
	return (EXIT_SUCCESS);
}
