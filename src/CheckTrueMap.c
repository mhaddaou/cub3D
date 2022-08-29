/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:16:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/29 18:01:49 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    CheckFirstLine(char **str)
{
    int i;
    
    i = 0;
    while (str[0][i])
    {
        if (str[0][i] == ' ' )
            if (str[1][i] != ' ' || str[1][i] != '1')
                err_hand(9);
        printf("%d\n", i);
        // if (str[0][i] != '1' || str[0][i] != ' ')
            // err_hand(9);
        i++;
    }
    
}
void    CheckTrueMap(t_cub *cub)
{
    CheckFirstLine(cub->map->TrueMap);
}