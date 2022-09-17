/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:55:17 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/17 18:38:01 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	calcule_true_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map->truemap[i])
		i++;
	return (i);
}

void	get_position_player(t_cub *cub)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = cub->map->truemap;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W'
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				cub->map->pos_x = j;
				cub->map->pos_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	cub->map->truemap[cub->map->pos_y][cub->map->pos_x] = '0';
}

int	check_no_so_ea_fc(t_map *map)
{
	if (map->n == 1)
		if (map->s == 1)
			if (map->e == 1)
				if (map->f == 1)
					if (map->c == 1)
						return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void    check_inside_map(t_cub *cub)
{
    int    i;
    int    j;

    i = 1;
    while (i < cub->map_height - 1)
    {
        j = 1;
        while (cub->map->truemap[i][j])
        {
            if (cub->map->truemap[i][j] == ' ')
            {
                if (!((cub->map->truemap[i + 1][j] == '1' || cub->map->truemap[i + 1][j] == ' ')
                    && (cub->map->truemap[i - 1][j] == '1' || cub->map->truemap[i - 1][j] == ' ')
                    && (cub->map->truemap[i][j - 1] == '1' || cub->map->truemap[i][j - 1] == ' ')
                    && (cub->map->truemap[i][j + 1] == '1'||  cub->map->truemap[i][j + 1] == ' ')))
                        err_hand2(16);
            }
            j++;
        }
        i++;
    }
}
