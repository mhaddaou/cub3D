/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckMapTwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:41:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	check_empty_line(char *line)
{
	if (!ft_strncmp(line, "\n", ft_strlen(line)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	check_short_name_two(t_map *map, char *str)
{
	if (!ft_strncmp(str, "EA", ft_strlen(str)))
	{
		get_info(map, 'E');
		map->e++;
	}
	else if (!ft_strncmp(str, "F", ft_strlen(str)))
	{
		get_info(map, 'F');
		map->f++;
	}
	else if (!ft_strncmp(str, "C", ft_strlen(str)))
	{
		get_info(map, 'C');
		map->c++;
	}
	else
		err_hand(5);
}

void	check_short_name(t_map *map, char *str, int i, int j)
{
	map->i = i;
	map->j = j;
	if (!ft_strncmp(str, "NO", ft_strlen(str)))
	{
		get_info(map, 'N');
		map->n++;
	}
	else if (!ft_strncmp(str, "SO", ft_strlen(str)))
	{
		get_info(map, 'S');
		map->s++;
	}
	else if (!ft_strncmp(str, "WE", ft_strlen(str)))
	{
		get_info(map, 'W');
		map->w++;
	}
	else
		check_short_name_two(map, str);
}
