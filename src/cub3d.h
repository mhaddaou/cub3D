/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 05:31:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/22 06:05:38 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# define BUFFER_SIZE (10)

typedef struct s_cub
{
	char	**map;
	int		map_height;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
}	t_cub;

int		check_extension(char *file_name);
char	**read_map(char *file_name);
int		open_count_line(char *file_name);
int		count_line(int fd);
void	ft_free(char **map);
void    ft_strerror(int err);
char    *ft_strdup(const char *s1);
char    *ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
void ft_putstr_fd(char *str, int fd);
char *gnl(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif