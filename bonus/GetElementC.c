/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetElementC.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:18:34 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 18:20:53 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	get_cb(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->ar2[i] != ' ' && map->ar2[i] != '\t' && map->ar2[i])
	{
		map->number[j] = map->ar2[i];
		i++;
		j++;
	}
	checkcolor(map->number);
	map->c_c.b = ft_atoi(map->number);
	ft_bzero(map->number, 10);
}

void	get_cg(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->ar2[i])
	{
		if (map->ar2[i] == ',')
		{
			checkcolor(map->number);
			map->c_c.g = ft_atoi(map->number);
			ft_bzero(map->number, 10);
			i++;
			break ;
		}
		map->number[j] = map->ar2[i];
		i++;
		j++;
	}
	get_cb(map, i);
}

void	get_c(t_map *map)
{
	int	i;

	i = 0;
	while (map->ar2[i])
	{
		if (map->ar2[i] == ',')
		{
			checkcolor(map->number);
			map->c_c.r = ft_atoi(map->number);
			ft_bzero(map->number, 10);
			i++;
			break ;
		}
		map->number[i] = map->ar2[i];
		i++;
	}
	get_cg(map, i);
}
