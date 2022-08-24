/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:43:54 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/23 17:46:49 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>



typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct all
{
    void *mlx;
    void *win;
    t_data data;
} t_all;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

#include <stdio.h>
int ground(t_all all)
{
    printf("ehh\n");
    my_mlx_pixel_put(&all.data, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(all.mlx, all.win, all.data.img,0,0);
    return (0);
}
int main ()
{
    t_all all;
    all.mlx = mlx_init();
    all.win = mlx_new_window(all.mlx, 500,500 , "cub");
    all.data.img = mlx_new_image(all.mlx, 500, 500);
    all.data.addr = mlx_get_data_addr(all.data.img,&all.data.bits_per_pixel, &all.data.line_length, &all.data.endian);
    mlx_loop_hook(all.mlx, &ground, &all);
    // ground(all);
    mlx_loop(all.mlx);
    
}