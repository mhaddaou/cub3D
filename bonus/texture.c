/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:34:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	getaddrtexture(t_cub *cub)
{
	cub->data1.addr = (int *) mlx_get_data_addr(cub->data1.img,
			&cub->data1.bits_per_pixel,
			&cub->data1.line_length, &cub->data1.endian);
	cub->data2.addr = (int *) mlx_get_data_addr(cub->data2.img,
			&cub->data2.bits_per_pixel, &cub->data2.line_length,
			&cub->data2.endian);
	cub->data3.addr = (int *) mlx_get_data_addr(cub->data3.img,
			&cub->data3.bits_per_pixel, &cub->data3.line_length,
			&cub->data3.endian);
	cub->data4.addr = (int *) mlx_get_data_addr(cub->data4.img,
			&cub->data4.bits_per_pixel, &cub->data4.line_length,
			&cub->data4.endian);
}

void	gettexture(t_cub *cub)
{
	cub->data1.img = mlx_xpm_file_to_image(cub->mlx, cub->map->n_texture,
			&cub->data1.width, &cub->data1.height);
	if (!cub->data1.img)
		err_hand2(17);
	cub->data2.img = mlx_xpm_file_to_image(cub->mlx, cub->map->w_texture,
			&cub->data2.width, &cub->data2.height);
	if (!cub->data2.img)
		err_hand2(17);
	cub->data3.img = mlx_xpm_file_to_image(cub->mlx, cub->map->s_texture,
			&cub->data3.width, &cub->data3.height);
	if (!cub->data3.img)
		err_hand2(17);
	cub->data4.img = mlx_xpm_file_to_image(cub->mlx, cub->map->e_texture,
			&cub->data4.width, &cub->data4.height);
	if (!cub->data4.img)
		err_hand2(17);
	getaddrtexture(cub);
}
