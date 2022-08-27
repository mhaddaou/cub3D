/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 05:31:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/27 11:33:08 by mhaddaou         ###   ########.fr       */
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
# include <math.h>

# define BUFFER_SIZE (10)
# define  PI (3.14159265)
# define TWO_PI (6.28318530)
# define ROWS (13)
# define COL (20)
# define FOV_ANGLE (60 * (PI / 180))
# define WINDOW_WIDTH (10)
# define WINDOW_HEIGHT (10)
# define MLX_ERROR 1
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLACK_PIXEL 0x041014
# define WHITE_PIXEL 0xFFFFFF
# define KEY_RIGHT (2)
# define KEY_LEFT (0)
# define KEY_UP (13)
# define KEY_DOWN (1) (




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
	float	y;
	int j;
	float x;
	int check ;
	
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
void    initializeWindow(t_cub *cub);
void getPosition(t_cub *cub);
double deg2rad(double deg);
double rad2deg(double rad);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void ddaAlgo(t_cub cub, float x1, float y1, int x2, int y2);
void DDA(t_cub *cub, int X0, int Y0, int X1, int Y1);
int key_hook(int key, t_cub *cub);
void printAll(t_cub *cub);
void check_map(t_cub *cub);
int ground(t_cub *all);
void put_player(t_cub *cub);
void    setup(t_cub *cub);
void printAllc(t_cub *cub);
int checkWalls(t_cub *cub);
int checkWallR(t_cub *cub);
int checkWallD(t_cub *cub);
int checkWallU(t_cub *cub);
void moveRight (t_cub *cub);
void moveLeft (t_cub *cub);
void moveUp (t_cub *cub);
void moveDown (t_cub *cub);
void printAllc(t_cub *cub);
void printAll(t_cub *cub);
void giVal(t_cub *cub, int i, int j, int color, int p);
void renderMap(t_cub *cub, int x, int y, int color);
#endif