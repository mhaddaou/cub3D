/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:25:37 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/09 19:06:59 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "../library/library.h"

#define XY (2)
#define TEXTURES (5)
# define DN (0)
# define DS (2)
# define DW (3)
# define DE (4)
# define RN = (1.5 *M_PI)
# define RS = (M_PI / 2)
# define RW = (M_PI)
# define RE = (0)


# define A (0)
# define S (1)
# define D (2)
# define W (13)
# define ESC (53)
# define LFT (123)
# define RGT (124)
# define VALIDE (0)
# define NVALIDE (1)

typedef struct s_color
{
	int R;
	int G;
	int B;
}	t_color;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_keys
{
	int w;
	int a;
	int s;
	int d;
	int rl;
	int rr;
}	t_keys;

typedef struct s_player
{
	double x;
	double y;
	double speed;
	double rotate;
}	t_player;
typedef struct s_map
{
	t_color F;
	t_color C;
	int		posX;
	int 	posY;
	char	*Ntexture;
	char	*Etexture;
	char	*Wtexture;
	char	*Stexture;
	char	**map;
	int		map_height;
	char 	*number;
	char	**TrueMap;
	int		n;
	int		w;
	int		e;
	int		s;
	int f;
	int c;
	int	check;
	int		i;
	int 	j;
	char	*ar;
	char	*ar2;
	char direction;
	
} t_map;

typedef struct s_cub
{
	t_map	*map;
	int		map_height;
	void	*mlx;
	void	*win;
	int rx;
	int ry;
	int x;
	int y;
	int fov;
	t_keys key;
	t_data data;
	void	*img_ground;
	double	stepx;
	double	stepy;
	t_player player;
	int		move_p;
	char check;
}	t_cub;

int		check_extension(char *file_name);
char	**read_map(char *file_name);
int		open_count_line(char *file_name);
int		count_line(int fd);
void	ft_free(char **map);
void	err_hand(int err);
void ft_init(t_cub *cub);
void initColor(t_map *map);
int ft_lent(t_cub *cub);
void init(t_map *map);
t_map    *CheckMap(t_map *map);
char *ft_strncpy(char *s1, char *s2, int len);
void check_line(t_map *map,int  i);
void    CheckShortName(t_map *map,char *str, int i, int j);
void GetInfo(t_map *map, char c);
int    CheckNoSoEaFC(t_map *map);
void GetTrueMap(t_cub *cub);
void ft_free1(t_map *map);
void    GetCB(t_map *map, int i);
void    GetCG(t_map *map, int i);
void GetC(t_map *map);
void GetF(t_map *map);
void    GetG(t_map *map, int i);
void    GetB(t_map *map, int i);
void    CheckTrueMap(t_cub *cub);
void CheckEmptyPath(t_map *map);
void InitSide(t_cub *cub);
void CheckObjects(t_cub *cub);
int CheckElement(t_cub *cub);
int 	CalculeTrueMap(t_cub *cub);

void 	CheckInsideMap(t_cub *cub);
void	GetPositionPlayer(t_cub *cub);
void ft_mlx(t_cub *cub);
void mouveLeft(t_cub *cub);
void mouveRight(t_cub *cub);
void mouveUp(t_cub *cub);
void mouveDown(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void CheckPrintTrueMap(t_cub *cub);
void DDA(t_cub *cub, int X0, int Y0, int X1, int Y1, int color);
void ddaALGO(t_cub *cub);
int update (t_cub *cub);
void ft_iniit(t_cub *cub);
int mouve(t_cub *cub);
void RotateLeft(t_cub *cub);
void RotateRight(t_cub *cub);
void FieldOfView(t_cub *cub);
void raycasting(t_cub *cub);
#endif
