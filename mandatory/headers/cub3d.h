/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 05:31:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/24 16:29:58 by mhaddaou         ###   ########.fr       */
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
#define  PI (3.14159265)
#define TWO_PI (6.28318530)
#define ROWS (13)
#define COL (20)
#define FOV_ANGLE (60 * (PI / 180))


#define WINDOW_WIDTH (10)
#define WINDOW_HEIGHT (10)

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define BLACK_PIXEL 0x041014
#define WHITE_PIXEL 0xFFFFFF




typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct	player
{
	float x;
	float y;
	float width;
	float height;
	int turnDirection;  // -1 turn left , + 1 turn right
	int walkDirection; // -1 walk back , + 1 walk front
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
} t_player;
typedef struct s_cub
{
	char	**map;
	int		map_height;
	int 	map_width;
	int i;
	int y;
	int j;
	int x;
	
	void	*mlx;
	void	*win;
	int		img_width;
	t_player player;
	t_data data;
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
void    initializeWindow(t_cub cub);

#endif