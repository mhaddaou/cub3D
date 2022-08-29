/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:02:07 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/29 11:16:37 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != NULL)
			free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (map)
		free(map);
	map = NULL;
}

void ft_free1(t_map *map)
{
	free(map->ar);
	free(map->ar2);
	free(map->number);
}
