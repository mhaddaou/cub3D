/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:13:33 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	move(t_cub *cub)
{
	if (cub->key.a == 1)
		move_left(cub);
	if (cub->key.d == 1)
		move_right(cub);
	if (cub->key.w == 1)
		move_up(cub);
	if (cub->key.s == 1)
		move_down(cub);
	if (cub->key.rl == 1)
		rotate_left(cub);
	if (cub->key.rr == 1)
		rotate_right(cub);
	return (EXIT_SUCCESS);
}

int	check_mv(int key, t_cub *cub)
{
	if (key == A)
		cub->key.a = 1;
	if (key == D)
		cub->key.d = 1;
	if (key == W)
		cub->key.w = 1;
	if (key == S)
		cub->key.s = 1;
	if (key == ESC)
		free_and_exit(cub);
	if (key == LFT)
		cub->key.rl = 1;
	if (key == RGT)
		cub->key.rr = 1;
	return (EXIT_SUCCESS);
}

int	check_mv2(int key, t_cub *cub)
{
	if (key == A)
		cub->key.a = 0;
	if (key == D)
		cub->key.d = 0;
	if (key == W)
		cub->key.w = 0;
	if (key == S)
		cub->key.s = 0;
	if (key == ESC)
		free_and_exit(cub);
	if (key == LFT)
		cub->key.rl = 0;
	if (key == RGT)
		cub->key.rr = 0;
	return (EXIT_SUCCESS);
}

void	ft_mlx(t_cub *cub)
{
	ft_iniit(cub);
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, cub->rx, cub->ry, "mhaddaou && izail");
	cub->data.img = mlx_new_image(cub->mlx, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img,
			&cub->data.bits_per_pixel, &cub->data.line_length,
			&cub->data.endian);
	update(cub);
	mlx_hook(cub->win, 17, 0, free_and_exit, cub);
	mlx_hook(cub->win, 2, 0, &check_mv, cub);
	mlx_hook(cub->win, 3, 0, &check_mv2, cub);
	mlx_loop_hook(cub->mlx, &move, cub);
	mlx_loop(cub->mlx);
}
