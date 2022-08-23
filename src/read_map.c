/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 06:26:42 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/22 06:41:13 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	count_line(int fd)
{
	char	*buffer;
	int		map_height;
	int		sz;

	map_height = 0;
	buffer = malloc (sizeof(char) * 2);
	if (!buffer)
		return (EXIT_FAILURE);
	while (1)
	{
		sz = read(fd, buffer, 1);
		buffer[1] = '\0';
		if (sz == -1)
		{
			ft_putstr_fd("Error\n read file\n", 2);
			free(buffer);
			return (EXIT_FAILURE);
		}
		if (sz == 0)
			break ;
		if (*buffer == '\n')
			map_height++;
	}
	free(buffer);
	return (map_height);
}

int	open_count_line(char *file_name)
{
	int	fd;
	int	map_height;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n\tThe file can't be open\n", 2);
		return (EXIT_FAILURE);
	}
	map_height = count_line(fd);
	close(fd);
	if (map_height == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (map_height);
}

char	**read_map(char *file_name)
{
	int		fd;
	int		i;
	int		map_height;
	char	**map;

	map_height = open_count_line(file_name);
	map = malloc (sizeof(char **) * (map_height + 1));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < map_height)
	{
		map[i] = gnl(fd);
		if (map[i++] == NULL)
			break ;
	}
	map[i] = NULL;
	close(fd);
	check_map_is_empty(map);
	return (map);
}
