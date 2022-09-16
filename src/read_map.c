/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:25:33 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/16 20:49:21 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**ft_read_map(t_map *map, char *path)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	holder = ft_strdup("");
	line = get_next_line(fd);
	holder_map = check_line_read(line, holder);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		ft_free_line(line, holder);
	}
	return (map->map = map_alloc(map, holder_map), free(holder_map),
		close(fd), map->map);
}


char	*check_line_read(char *line, char *holder)
{
	char	*str;

	if (!line)
	{
		printf("invalid map!!\n");
		free(line);
		free(holder);
		exit(EXIT_FAILURE);
	}
	str = ft_strjoin(holder, line);
	free(line);
	free(holder);
	return (str);
}

void	ft_free_line(char *line, char *holder)
{
	free(line);
	free(holder);
}


char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**map_alloc(t_map *map, char *line)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (line[i])
	{
		if (line[i] == '\n')
			k++;
		i++;
	}
	map->map = (char **)malloc((k + 1) * sizeof(char *));
	if (!map->map)
		return (NULL);
	return (fill_map(line, map));
}

char	**fill_map(char *line, t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i] != '\0')
		{
			map->map[k] = word_dup(line, j, i);
			j = i + 1;
			k++;
		}
		i++;
	}	
	map->map[k] = word_dup(line, j, i);
	map->map[++k] = 0;
	return (map->map);
}

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
