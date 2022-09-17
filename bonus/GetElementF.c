/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetElementF.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:54:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	get_b(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->ar[i] != ' ' && map->ar[i] != '\t' && map->ar[i])
	{
		map->number[j] = map->ar[i];
		i++;
		j++;
	}
	checkcolor(map->number);
	map->f_c.b = ft_atoi(map->number);
	ft_bzero(map->number, 10);
}

void	get_g(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->ar[i])
	{
		if (map->ar[i] == ',')
		{
			checkcolor(map->number);
			map->f_c.g = ft_atoi(map->number);
			ft_bzero(map->number, 10);
			i++;
			break ;
		}
		map->number[j] = map->ar[i];
		i++;
		j++;
	}
	get_b(map, i);
}

void	check_ar(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] == ',')
			check++;
		i++;
	}
	if (check != 2)
		err_hand2(17);
	check_ar22(str);
}

void	get_f(t_map *map)
{
	int	i;

	i = 0;
	check_ar(map->ar);
	while (map->ar[i])
	{
		if (map->ar[i] == ',')
		{
			checkcolor(map->number);
			map->f_c.r = ft_atoi(map->number);
			ft_bzero(map->number, 10);
			i++;
			break ;
		}
		map->number[i] = map->ar[i];
		i++;
	}
	get_g(map, i);
}

void	get_info(t_map *map, char c)
{
	int	i;
	int	j;

	map->check++;
	i = map->i;
	j = map->j;
	if (c == 'N')
		map->n_texture = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
	else if (c == 'S')
		map->s_texture = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
	else if (c == 'W')
		map->w_texture = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
	else if (c == 'E')
		map->e_texture = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
	else if (c == 'F')
	{
		map->ar = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
		get_f(map);
	}
	else if (c == 'C')
	{
		map->ar2 = ft_substr(map->map[i], j, ft_strlen(map->map[i]));
		get_c(map);
	}
}
