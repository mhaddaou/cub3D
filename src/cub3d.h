/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 05:31:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/23 12:43:08 by mhaddaou         ###   ########.fr       */
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

#define WINDOW_WIDTH (1700)
#define WINDOW_HEIGHT (2550)

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

typedef struct player
{
	int playerX;
	int playerY;
}	t_player;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_cub
{
	char	**map;
	int		map_height;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	t_player player;
	t_data img_mlx;
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
void    check_map_is_empty(char **map);
void    initializeWindow(t_cub *cub);

#endif