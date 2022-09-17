/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:25:37 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/17 22:33:56 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
// # include "../library/library.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"

# define BUFFER_SIZE (10)
# define XY (2)
# define TEXTURES (5)
# define DN (0)
# define DS (2)
# define DW (3)
# define DE (4)
# define CFOV  (0xbac8ff)

# define A (0)
# define S (1)
# define D (2)
# define W (13)
# define ESC (53)
# define LFT (123)
# define RGT (124)
# define VALIDE (0)
# define NVALIDE (1)
# define TILE_SIZE 30

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	void	*img;
	int		*addr;
	void	*img2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_data2
{
	void	*img;
	int		*addr;
	void	*img2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data2;

typedef struct s_hv
{
	double	xh;
	double	yh;
	double	xv;
	double	yv;
	double	x;
	double	ysteph;
	double	xstepv;
	double	y;
}	t_hv;

typedef struct s_facing
{
	bool	is_facing_down;
	bool	is_facing_up;
	bool	is_facing_left;
	bool	is_facing_right;
}	t_facing;

typedef struct s_bxy
{
	double	_bx;
	double	_by;
	double	_xstep;
	double	_ystep;
}	t_bxy;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	rl;
	int	rr;
}	t_keys;

typedef struct s_player
{
	double	x;
	double	y;
	double	speed;
	double	rotate;
}	t_player;

typedef struct s_ray
{
	int		dof;
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
	int		mx;
	int		my;
	int		mp;
	int		r;
}	t_ray;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		height;
	int		width;
}	t_texture;

typedef struct s_map
{
	t_color	f_c;
	t_color	c_c;
	int		pos_x;
	int		pos_y;
	char	*n_texture;
	char	*e_texture;
	char	*w_texture;
	char	*s_texture;
	char	**map;
	int		map_height;
	char	*number;
	char	**truemap;
	int		n;
	int		w;
	int		e;
	int		s;
	int		f;
	int		c;
	int		check;
	int		i;
	int		j;
	char	*ar;
	char	*ar2;
	char	direction;
	int		i0;
	int		j0;
}	t_map;

typedef struct s_cub
{
	int			i_ray;
	t_map		*map;
	int			map_height;
	void		*mlx;
	void		*win;
	int			rx;
	int			ry;
	int			x;
	int			y;
	int			l;
	int			fov;
	t_hv		hv;	
	t_keys		key;
	t_data		data;
	void		*img_ground;
	double		stepx;
	double		stepy;
	t_data2		data1;
	t_data2		data2;
	t_data2		data3;
	t_data2		data4;
	double		wall_height;
	double		dist_project_plane;
	double		x_offset;
	int			start;
	int			end;
	double		y_offset;
	t_player	player;
	t_facing	facing;
	t_bxy		_bxy;
	double		xt;
	double		yt;
	int			x0;
	int			y0;
	int			move_p;
	t_ray		ray;
	char		check;
	int			stepsdda;
	double		y_inc;
	double		x_inc;
}	t_cub;

int		check_extension(char *file_name);
char	**read_map(char *file_name);
int		open_count_line(char *file_name);
int		count_line(int fd);
void	ft_free(char **map);
void	err_hand(int err);
void	err_hand2(int err);
void	ft_init(t_cub *cub);
void	init_color(t_map *map);
int		ft_lent(t_cub *cub);
void	init(t_map *map);
t_map	*check_map(t_map *map);
char	*ft_strncpy(char *s1, char *s2, int len);
void	check_line(t_map *map, int i);
void	check_short_name(t_map *map, char *str, int i, int j);
void	get_info(t_map *map, char c);
int		check_no_so_ea_fc(t_map *map);
void	get_true_map(t_cub *cub);
void	ft_free1(t_map *map);
void	get_cb(t_map *map, int i);
void	get_cg(t_map *map, int i);
void	get_c(t_map *map);
void	get_f(t_map *map);
void	get_g(t_map *map, int i);
void	get_b(t_map *map, int i);
void	check_true_map(t_cub *cub);
void	check_empty_path(t_map *map);
void	init_side(t_cub *cub);
void	check_objects(t_cub *cub);
int		check_element(t_cub *cub);
int		calcule_true_map(t_cub *cub);
void	check_inside_map(t_cub *cub);
void	get_position_player(t_cub *cub);
void	ft_mlx(t_cub *cub);
void	move_left(t_cub *cub);
void	move_right(t_cub *cub);
void	move_up(t_cub *cub);
void	move_down(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	check_print_true_map(t_cub *cub);
void	dda(t_cub *cub, int x1, int y1);
void	ddaALGO(t_cub *cub);
int		update(t_cub *cub);
void	ft_iniit(t_cub *cub);
int		move(t_cub *cub);
void	rotate_left(t_cub *cub);
void	rotate_right(t_cub *cub);
void	field_of_view(t_cub *cub);
void	raycasting(t_cub *cub);
int		lenss(char **str);
void	gettexture(t_cub *cub);
void	getaddrtexture(t_cub *cub);
void	my_mlx_pixel_put2(t_data2 *data2, int x, int y, int color);
int		ret_color(t_cub *cub, int x);
void	field_of_view_mini(t_cub *cub);
int		stephorizontale(t_cub *cub, double rd, double x0, double y0);
int		stepvertical(t_cub *cub, double rd, double x0, double y0);
int		check_rays_map(t_cub *cub, double bx, double by);
int		retlen(char **str);
void	check_wall_mini(t_cub *cub, double x0, double y0, double rd);
void	check_wall(t_cub *cub, double x0, double y0, double rd);
void	calcul_distancemini(t_cub *cub, double x0, double y0, double rd);
void	calcul_distance(t_cub *cub, double x0, double y0, double rd);
void	convert_3d(t_cub *cub, double distray, double rd);
void	draw_texture(t_cub *cub, char c, int column_id, int order);
void	checkcolorrange(int r);
void	checkcolor(char *str);
void	draw_text_order4(t_cub *cub, char c, int column_id);
void	draw_text_order3(t_cub *cub, char c, int column_id);
void	draw_text_order2(t_cub *cub, char c, int column_id);
void	draw_text_order1(t_cub *cub, char c, int column_id);
void	err_hand2(int err);
void	check_print_true_map2(t_cub *cub, int x, int y);
int		check_empty_line(char *line);
void	print_flor_ciel(t_cub *cub);
int		free_and_exit(t_cub *cub);
void	calcul_element(t_cub *cub);
void	check_walls(char **str);
void	check_last_line(char **str);
void	check_first_line(char **str);
void	check_ar(char *str);

char    **ft_read_map(t_map *map, char *path);
// char	*check_read(char *line, char *holder);
void	ft_free_line(char *line, char *holder);
char	**map_alloc(t_map *map, char *line);
char	*word_dup(char *str, int start, int finish);
char	**fill_map(char *line, t_map *map);
char	*check_line_read(char *line, char *holder);
void check_extension_texture(t_map *map);
int check_texture(char *file_name);
#endif