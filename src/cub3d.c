/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:51:14 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/31 11:12:10 by mhaddaou         ###   ########.fr       */
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
	map.map = read_map(file_name);
	map.map_height = open_count_line(file_name);
	init(&map);
	cub.map = CheckMap(&map);

    CheckEmptyPath(&map);
    CheckEmptyPath(&map);
	GetTrueMap(&cub);
	int i = 0;
	CheckTrueMap(&cub);
	while (cub.map->TrueMap[i])
	{
		printf("%s\n", cub.map->TrueMap[i]);
		i++;
	}
	printf("blabla fik al9lawi");
	
	
	
	sleep(1111);
	
}
