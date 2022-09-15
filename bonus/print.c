/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:13:36 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 18:20:53 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	print_flor(t_cub *cub)
{
	int	i;
	int	j;
	int	clr_f;

	i = cub->ry / 2;
	clr_f = create_rgb(cub->map->f_c.r, cub->map->f_c.g, cub->map->f_c.b);
	while (i < cub->ry)
	{
		j = 0;
		while (j < cub->rx)
		{
			my_mlx_pixel_put(&cub->data, j, i, clr_f);
			j++;
		}
		i++;
	}
}

void	print_ciel(t_cub *cub)
{
	int	i;
	int	j;
	int	clr_c;

	i = 0;
	clr_c = create_rgb(cub->map->c_c.r, cub->map->c_c.g, cub->map->c_c.b);
	while (i < (cub->ry / 2))
	{
		j = 0;
		while (j < cub->rx)
		{
			my_mlx_pixel_put(&cub->data, j, i, clr_c);
			j++;
		}
		i++;
	}
}

void	print_flor_ciel(t_cub *cub)
{
	print_ciel(cub);
	print_flor(cub);
}
