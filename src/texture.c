/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:34:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/13 22:51:33 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void getAddrTexture(t_cub *cub)
{
    
    cub->data2->addr = (int *) mlx_get_data_addr(cub->data2[0].img, &cub->data2->bits_per_pixel, &cub->data2->line_length, &cub->data2->endian);
    
   
    // cub->data.img
    // for (int i = 0; i<cub->data2->height ;i++)
    // {
    //     for (int j = 0; j < cub->data2->width;j++)
    //     {
    //         cub->data.addr[i * cub->data2->width + j] = cub->data2->addr[i * cub->data2->width+ j];
    //     }
    // }
}


void getTexture(t_cub *cub)
{
    cub->data2[0].img = mlx_xpm_file_to_image(cub->mlx, cub->map->Ntexture, &cub->data2[0].width, &cub->data2[0].height);
    // cub->tex[1].img = mlx_xpm_file_to_image(cub->mlx, cub->map->Wtexture,& cub->tex[1].width,& cub->tex[1].height);
    // cub->tex[2].img = mlx_xpm_file_to_image(cub->mlx, cub->map->Stexture,& cub->tex[2].width, &cub->tex[2].height);
    // cub->tex[3].img = mlx_xpm_file_to_image(cub->mlx, cub->map->Etexture,& cub->tex[3].width, &cub->tex[3].height);
    // printf("%s\n", cub->map->Ntexture);
    // if (!mlx_xpm_file_to_image(cub->mlx, "./textures/red.xpm", &cub->tex[0].width, &cub->tex[0].height))
    //     printf("Error\n");
    getAddrTexture(cub);
}
