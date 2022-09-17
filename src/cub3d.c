/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:51:14 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/17 22:42:40 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub	cub;
	t_map	map;
	char	*file_name;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nThe argument is not correct.\n", 2);
		ft_putstr_fd("\tUsage: ./so_long [map.ber]\n", 2);
		return (EXIT_FAILURE);
	}
	if (check_extension(argv[1]) == -1)
	{
		ft_putstr_fd("Error\nThe extension of the map is not correct.\n", 2);
		return (EXIT_FAILURE);
	}
	file_name = argv[1];
	map.map = ft_read_map(&map,file_name);
	init(&map);
	cub.map = check_map(&map);
	check_empty_path(&map);
	get_true_map(&cub);
	check_true_map(&cub);
}
