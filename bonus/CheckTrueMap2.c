/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:19:16 by izail             #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	check_element(t_cub *cub)
{
	if (cub->map->n == 1)
		if (cub->map->s == 0)
			if (cub->map->e == 0)
				if (cub->map->w == 0)
					return (DN);
	if (cub->map->n == 0)
		if (cub->map->s == 1)
			if (cub->map->e == 0)
				if (cub->map->w == 0)
					return (DS);
	if (cub->map->n == 0)
		if (cub->map->s == 0)
			if (cub->map->e == 1)
				if (cub->map->w == 0)
					return (DE);
	if (cub->map->n == 0)
		if (cub->map->s == 0)
			if (cub->map->e == 0)
				if (cub->map->w == 1)
					return (DW);
	return (EXIT_FAILURE);
}

void	get_direction(t_cub *cub)
{
	if (cub->map->check == DN)
		cub->map->direction = 'n';
	else if (cub->map->check == DS)
		cub->map->direction = 's';
	else if (cub->map->check == DW)
		cub->map->direction = 'w';
	else if (cub->map->check == DE)
		cub->map->direction = 'e';
}

void	calcul_element(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map->truemap[i])
	{
		j = 0;
		while (cub->map->truemap[i][j])
		{
			if (cub->map->truemap[i][j] == 'N')
				cub->map->n++;
			if (cub->map->truemap[i][j] == 'S')
				cub->map->s++;
			if (cub->map->truemap[i][j] == 'W')
				cub->map->w++;
			if (cub->map->truemap[i][j] == 'E')
				cub->map->e++;
			j++;
		}
		i++;
	}
	cub->map->check = check_element(cub);
	if (cub->map->check == EXIT_FAILURE)
		err_hand2(15);
	get_direction(cub);
}

void	check_objects(t_cub *cub)
{
	char	**map;
	int		j;
	int		i;

	i = 0;
	map = cub->map->truemap;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
				if (map[i][j] != '0')
					if (map[i][j] != 'N')
						if (map[i][j] != 'S')
							if (map[i][j] != 'W')
								if (map[i][j] != 'E')
									if (map[i][j] != ' ')
										err_hand2(14);
			j++;
		}
		i++;
	}
	calcul_element(cub);
}
