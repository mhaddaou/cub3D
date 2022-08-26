/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 06:36:51 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/26 19:05:13 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void    check_map_is_empty(char **map)
{
    if (!*map)
        ft_strerror(2);
}
int checkWalls(t_cub *cub)
{
    printf("x == %f\n",cub->player.x );
    printf("y == %f\n",cub->player.y );
    int x;
    int y;
    y = 0;
    while (cub->map[y])
    {
        x = 0;
        while (cub->map[y][x])
        {
            if (cub->map[y][x] == '1')
                if (((int)cub->player.x == x) && ((int)cub->player.y == y))
                    return (EXIT_FAILURE);
            x++;
        }
        y++;
    }
    return (EXIT_SUCCESS);
}