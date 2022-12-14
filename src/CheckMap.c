/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:47:34 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/17 22:59:36 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_line(t_map *map, int i)
{
	int		j;
	int		index;
	char	ar[BUFFER_SIZE];

	index = 0;
	j = 0;
	if (check_empty_line(map->map[i]) == EXIT_FAILURE)
		return ;
	while (map->map[i][j] == ' ')
		j++;
	while (map->map[i][j] != ' ' && map->map[i][j])
	{
		ar[index] = map->map[i][j];
		j++;
		index++;
	}
	ar[index] = '\0';
	check_short_name(map, ar, i, j + 1);
}

void	check_empty_path(t_map *map)
{
	if (!*map->n_texture)
		err_hand(8);
	if (!*map->s_texture)
		err_hand(8);
	if (!*map->w_texture)
		err_hand(8);
	if (!*map->e_texture)
		err_hand(8);
}

int	check_texture(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (file_name[len - 4] == '.')
		if (file_name[len - 3] == 'x')
			if (file_name[len - 2] == 'p')
				if (file_name[len - 1] == 'm')
					return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	check_extension_texture(t_map *map)
{
	if (check_texture(map->n_texture) == EXIT_FAILURE)
		err_hand2(17);
	if (check_texture(map->s_texture) == EXIT_FAILURE)
		err_hand2(17);
	if (check_texture(map->w_texture) == EXIT_FAILURE)
		err_hand2(17);
	if (check_texture(map->e_texture) == EXIT_FAILURE)
		err_hand2(17);
}

t_map	*check_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] && map->check != 6)
	{
		check_line(map, i);
		i++;
	}
	if (check_no_so_ea_fc(map) == EXIT_FAILURE)
		err_hand(6);
	map->check = i;
	check_extension_texture(map);
	ft_free1(map);
	return (map);
}
