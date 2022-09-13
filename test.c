#include<mlx.h>
#include<stdio.h>
#   include<stdlib.h>

typedef struct	s_data {
	void	*img;
	int	*addr;
	void 	*img2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_data2 {
	void	*img;
	int	*addr;
	void 	*img2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int width;
    int height;
}				t_data2;

typedef struct s_cub
{
    void *mlx;
    void *win;
    t_data *data;
    t_data2 *data2;
}t_cub;

int main(void)
{
    t_cub   *cub;

    cub = (t_cub *)malloc(sizeof(t_cub));
    cub->data = (t_data *)malloc(sizeof(t_data));
    cub->data2 = (t_data2 *)malloc(sizeof(t_data2));
    cub->mlx = mlx_init();
    cub->win = mlx_new_window(cub->mlx, 800, 600, "window");
    cub->data->img = mlx_new_image(cub->mlx, 800,600);
    cub->data->addr = (int *)mlx_get_data_addr(cub->data->img, &cub->data->bits_per_pixel, &cub->data->line_length, &cub->data->endian);
    cub->data2->img = mlx_xpm_file_to_image(cub->mlx, "./textures/red.xpm", &cub->data2->width, &cub->data2->height);
    cub->data2->addr = (int *)  mlx_get_data_addr(cub->data2->img, &cub->data2->bits_per_pixel, &cub->data->line_length,&cub->data->endian);
    for (int i = 0; i<cub->data2->height ;i++)
    {
        for (int j = 0; j < cub->data2->width;j++)
        {
            cub->data->addr[(i * TI) * cub->data2->width + j] = cub->data2->addr[i * 1
            0 * cub->data2->width+ j];
        }
    }
    mlx_put_image_to_window(cub->mlx,cub->win, cub->data->img,0,0);
    mlx_loop(cub->mlx);
}