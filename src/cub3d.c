/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:23:12 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/22 06:08:40 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		int i = 0;
		while (cub.map[i])
		{
			printf("%s\n", cub.map[i]);
			i++;
		}
		
	}
	else
		printf("error");
}
