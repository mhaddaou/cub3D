/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 06:27:38 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/23 16:05:29 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub	cub;
	char	*file_name;
	if (argc > 1)
	{
		
		if (check_extension(argv[1]) == -1)
			ft_strerror(1);
		file_name = argv[1];
		cub.map = read_map(file_name);
		
		// int i = 0;
		// while (cub.map[i])
		// {
		// 	printf("%s\n", cub.map[i]);
		// 	i++;
		// }
		initializeWindow(cub);
		// cub.mlx = mlx_init();
		// cub.win = mlx_new_window(cub.mlx, 800, 600, "hello");
		// mlx_loop(cub.mlx);
		
	}
	else
		printf("error");
}
