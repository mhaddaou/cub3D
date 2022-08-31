/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:55:17 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/31 14:07:31 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


 int CalculeTrueMap(t_cub *cub)
 {
     int i;

     i = 0;
     while (cub->map->TrueMap[i])
        i++;
    return (i);
 }
// void CheckInsideMap(t_cub *cub)
// {
//     int i;
//     int j;
    
//     i = 1;
//     while (i < cub->map_height)
//     {
//         j = 1;
//             while (cub->map->TrueMap[i][j])
//             {
//                 if (cub->map->TrueMap[i][j] == ' ')
//                     if ()
//             }
        
//     }
    
// }