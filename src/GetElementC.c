/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetElementC.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:18:34 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/17 00:14:24 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	check_ar(map->ar2);
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
