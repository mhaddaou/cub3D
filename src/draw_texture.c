/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:34:25 by izail             #+#    #+#             */
/*   Updated: 2022/09/17 23:13:13 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_text_order4(t_cub *cub, char c, int column_id)
{
	int	dist;
	int	y;

	check_h_or_v(cub, c);
	cub->start = (cub->ry / 2) - (cub->wall_height / 2);
	if (cub->start < 0)
		cub->start = 0;
	cub->end = (cub->ry / 2) + (cub->wall_height / 2);
	if (cub->end > cub->ry)
		cub->end = cub->ry;
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

	check_h_or_v(cub, c);
	cub->start = (cub->ry / 2) - (cub->wall_height / 2);
	cub->end = (cub->ry / 2) + (cub->wall_height / 2);
	if (cub->start < 0)
		cub->start = 0;
	y = cub->start;
	if (cub->end > cub->ry)
		cub->end = cub->ry;
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

	check_h_or_v(cub, c);
	cub->start = (cub->ry / 2) - (cub->wall_height / 2);
	cub->end = (cub->ry / 2) + (cub->wall_height / 2);
	if (cub->start < 0)
		cub->start = 0;
	y = cub->start;
	if (cub->end > cub->ry)
		cub->end = cub->ry;
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

	check_h_or_v(cub, c);
	cub->start = (cub->ry / 2) - (cub->wall_height / 2);
	cub->end = (cub->ry / 2) + (cub->wall_height / 2);
	if (cub->start < 0)
		cub->start = 0;
	y = cub->start;
	if (cub->end > cub->ry)
		cub->end = cub->ry;
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
