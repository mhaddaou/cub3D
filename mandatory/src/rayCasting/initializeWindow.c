#include "../../headers/cub3d.h"



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    setup(t_cub *cub)
{
    cub->player.width = 5;
    cub->player.height = 5;
    cub->player.turnDirection = 0;
    cub->player.walkDirection = 0;
    cub->player.rotationAngle = PI / 2;
    cub->player.walkSpeed = 100;
    cub->player.turnSpeed = 45 * (PI / 180); 
}

int len_height(t_cub *cub)
{
    int i = 0;
    while (cub->map[i])
        i++;
    return (i);
}

void    initializeWindow(t_cub *cub)
{
    cub->mlx = mlx_init();
    
    cub->win = mlx_new_window(cub->mlx, 1500, 1000 , "cub");
    if (!cub->win)
        ft_strerror(3);
    cub->data.img = mlx_new_image(cub->mlx, 1500, 1000);
    cub->data.addr = mlx_get_data_addr(cub->data.img,&cub->data.bits_per_pixel, &cub->data.line_length, &cub->data.endian);
    cub->map_width = (int)ft_strlen(cub->map[0]);
    cub->map_height = len_height(cub);
    printAll(cub);
    mlx_hook(cub->win, 2, 0, key_hook, cub);
    mlx_loop(cub->mlx);
    mlx_destroy_image(cub->mlx, cub->data.img);
}