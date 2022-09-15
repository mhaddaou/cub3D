/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:34:25 by izail             #+#    #+#             */
/*   Updated: 2022/09/14 17:54:43 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_text_order4(t_cub *cub, char c, int column_id)
{
	int	dist;
	int	y;

	if (c == 'h')
	{
		cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data4.width;
	}
	else
	{
		cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data4.width;
	}
	cub->start = (cub->ry / 2) - (cub->wall_height / 2);
	cub->end = (cub->ry / 2) + (cub->wall_height / 2);
	y = cub->start;
	while (y < cub->end)
	{
		dist = y + (cub->wall_height / 2) - (cub->ry / 2);
		cub->y_offset = dist * ((float)(cub->data4.height) / cub->wall_height);
		cub->data.addr[y * cub->rx + column_id]
			= cub->data4.addr[(int)(cub->y_offset)
			* (cub->data4.width) + (int)cub->x_offset];
		y++;
	}
}

void	draw_text_order1(t_cub *cub, char c, int column_id)
{
	int	dist;
	int	y;

	if (c == 'h')
	{
		cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data1.width;
	}
	else
	{
		cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data1.width;
	}
	cub->start = (cub->ry / 2) - (cub->wall_height / 2);
	cub->end = (cub->ry / 2) + (cub->wall_height / 2);
	y = cub->start;
	while (y < cub->end)
	{
		dist = y + (cub->wall_height / 2) - (cub->ry / 2);
		cub->y_offset = dist * ((float)(cub->data1.height) / cub->wall_height);
		cub->data.addr[y * cub->rx + column_id]
			= cub->data1.addr[(int)(cub->y_offset)
			* (cub->data1.width) + (int)cub->x_offset];
		y++;
	}
}

void	draw_text_order2(t_cub *cub, char c, int column_id)
{
	int	dist;
	int	y;

	if (c == 'h')
	{
		cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data2.width;
	}
	else
	{
		cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data2.width;
	}
	cub->start = (cub->ry / 2) - (cub->wall_height / 2);
	cub->end = (cub->ry / 2) + (cub->wall_height / 2);
	y = cub->start;
	while (y < cub->end)
	{
		dist = y + (cub->wall_height / 2) - (cub->ry / 2);
		cub->y_offset = dist * ((float)(cub->data2.height) / cub->wall_height);
		cub->data.addr[y * cub->rx + column_id]
			= cub->data2.addr[(int)(cub->y_offset)
			* (cub->data2.width) + (int)cub->x_offset];
		y++;
	}
}

void	draw_text_order3(t_cub *cub, char c, int column_id)
{
	int	dist;
	int	y;

	if (c == 'h')
	{
		cub->x_offset = cub->hv.x / TILE_SIZE - (int)(cub->hv.x / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data3.width;
	}
	else
	{
		cub->x_offset = cub->hv.y / TILE_SIZE - (int)(cub->hv.y / TILE_SIZE);
		cub->x_offset = cub->x_offset * cub->data3.width;
	}
	cub->start = (cub->ry / 2) - (cub->wall_height / 2);
	cub->end = (cub->ry / 2) + (cub->wall_height / 2);
	y = cub->start;
	while (y < cub->end)
	{
		dist = y + (cub->wall_height / 2) - (cub->ry / 2);
		cub->y_offset = dist * ((float)(cub->data3.height) / cub->wall_height);
		cub->data.addr[y * cub->rx + column_id]
			= cub->data3.addr[(int)(cub->y_offset)
			* (cub->data3.width) + (int)cub->x_offset];
		y++;
	}
}

void	draw_texture(t_cub *cub, char c, int column_id, int order)
{
	int	dist;
	int	y;

	if (order == 4)
		draw_text_order4(cub, c, column_id);
	else if (order == 1)
		draw_text_order1(cub, c, column_id);
	else if (order == 2)
		draw_text_order2(cub, c, column_id);
	else if (3)
		draw_text_order3(cub, c, column_id);
}
