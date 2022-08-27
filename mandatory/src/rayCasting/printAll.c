/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printAll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:22:08 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/27 11:30:34 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"


void put_player(t_cub *cub)
{
    int x = cub->player.x * 30;
    int y = cub->player.y * 30;
    
    while (y < (cub->player.y * 30 )  + 10)
    {
        x = cub->player.x * 30;

        while (x < (cub->player.x * 30) + 10)
        {
            my_mlx_pixel_put(&cub->data, x, y, RED_PIXEL);
            x++;
        }
        y++;
    }
}

int ground(t_cub *all)
{
    int i = 0;
    int j;
    while (i < all->map_height * 30)
    {
        j = 0;
        while (j < all->map_width * 30)
        {
            my_mlx_pixel_put(&all->data, j,i, GREEN_PIXEL);
            j++;
        } 
        i++;  
    }
    return (0);
}
void printAllc(t_cub *cub)
{
    ground(cub);
    check_map(cub);
    getPosition(cub);
    setup(cub);
    put_player(cub);
    DDA(cub, cub->player.x * 30, cub->player.y * 30, (cub->player.x + 1) * 30, (cub->player.y + 1) * 30);

}

void printAll(t_cub *cub)
{
    
    ground(cub);
    check_map(cub);
    getPosition(cub);
    setup(cub);
    put_player(cub);
    DDA(cub, cub->player.x * 30, cub->player.y * 30, (cub->player.x + 1) * 30, (cub->player.y + 1) * 30);
}