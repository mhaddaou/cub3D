/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:55:29 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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

char	*check_line_read(char *line, char *holder)
{
	char	*str;

	if (!line)
	{
		ft_putstr_fd("Error\n\t Invalid map", 2);
		free(line);
		free(holder);
		exit(EXIT_FAILURE);
	}
	str = ft_strjoin(holder, line);
	free(line);
	free(holder);
	return (str);
}
