/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetTrueMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:55:47 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/17 19:10:40 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	go_to_c(t_map *map, int i, int j)
{
	int	x;

	x = 0;
	while (i < j)
	{
		
		map->truemap[x] = ft_strdup(map->map[i]);
		i++;
		x++;
	}
	map->truemap[x] = NULL;
}

void	initialize_true_map(t_cub *cub, int i, int j)
{
	int	len;

	len = (j - i) + 1;
	cub->map->truemap = (char **) malloc (sizeof(char *) * len);
	if (!cub->map->truemap)
		err_hand(1);
	go_to_c(cub->map, i, j);
}

void	get_true_map(t_cub *cub)
{
	int	i;
	int	j;
	char **str;

	str = cub->map->map;
	i = cub->map->check;
	while (str[i])
	{
		if (ft_strncmp(str[i], "\n", ft_strlen(str[i])))
			break;
		i++;
	}

	if (!cub->map->map[i])
		err_hand(0);

	j = i;
	while (cub->map->map[j]
		&& (ft_strncmp(cub->map->map[j], "\n", ft_strlen(cub->map->map[j]))))
		j++;
	initialize_true_map(cub, i, j);
}
