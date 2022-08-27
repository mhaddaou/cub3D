/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posPlayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:52:09 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/27 11:28:05 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void getPosition(t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while ( cub->map[i])
    {
        j = 0;
        while (cub->map[i][j])
        {
            if (cub->map[i][j] == 'P')
            {
                cub->player.x = j;
                cub->player.y = i;
            }
                j++;
        }
        i++;
    }
    
}
