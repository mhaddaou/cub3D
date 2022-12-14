/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_hand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:54:38 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	err_hand(int err)
{
	if (err == 0)
		ft_putstr_fd("Error\n=> The map is empty", 2);
	if (err == 1)
		ft_putstr_fd("Error\n=> Allocation failed", 2);
	if (err == 3)
		ft_putstr_fd("Error\n=>  error inside map no or so ea", 2);
	if (err == 4)
		ft_putstr_fd("Error\n=> path_to_the_north_texture", 2);
	if (err == 5)
		ft_putstr_fd("Error\n=> In the texture or colors", 2);
	if (err == 6)
		ft_putstr_fd("Error\n=> In the texture or color is more than one", 2);
	if (err == 7)
		ft_putstr_fd("Error\n=> On the first line in not all is 1", 2);
	if (err == 8)
		ft_putstr_fd("Error\n=> path", 2);
	if (err == 9)
		ft_putstr_fd("Error\n=> line one", 2);
	exit(EXIT_FAILURE);
}

void	err_hand2(int err)
{
	if (err == 10)
		ft_putstr_fd("Error\n=> map", 2);
	if (err == 11)
		ft_putstr_fd("Error\n=> color out of range", 2);
	if (err == 12)
		ft_putstr_fd("Error\n=> Walls !", 2);
	if (err == 13)
		ft_putstr_fd("Error\n=>  color in not digit", 2);
	if (err == 14)
		ft_putstr_fd("Error\n=> other characters", 2);
	if (err == 15)
		ft_putstr_fd("Error\n=> Duplicate or not found any direction", 2);
	if (err == 16)
		ft_putstr_fd("Error\n=> Map is invalid", 2);
	if (err == 17)
		ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
