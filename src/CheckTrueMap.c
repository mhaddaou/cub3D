/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:16:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/31 15:40:41 by izail            ###   ########.fr       */
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
            if (str[1][i] != ' ' && str[1][i] != '1')
                    err_hand(9);
        if (str[0][i] == ' ' && str[1][i] == '1')
            if (str[1][i + 1] != '1')   
                err_hand(9);
        if (str[0][i] != '1' && str[0][i] != ' ')   
            err_hand(9);
        if ((str[0][i] == '1'&& str[0][i + 1] == '\0') && str[1][i + 1] == '0')
            err_hand(9);
        i++;
    }
}

void    CheckLastLine(char **str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (str[len])
        len++;
    len--;
      while (str[len][i])
    {
        if (str[len][i] == ' ' )
            if (str[len - 1][i] != ' ' && str[len - 1][i] != '1')
                    err_hand(10);
        if (str[len][i] == ' ' && str[1][i] == '1')
            if (str[len - 1][i + 1] != '1')   
                err_hand(10);
        if (str[len][i] != '1' && str[len][i] != ' ')   
            err_hand(10);
        if ((str[len][i] == '1'&& str[len][i + 1] == '\0') && str[len - 1][i + 1] == '0')
            err_hand(10);
        i++;
    }
}

void    CheckWalls(char **str)
{
    int i;
    int j;
    int len;

    i = 1;
    len = 0;
    
    while (str[i])
	{
        j = 0;
        len = ft_strlen(str[i]) - 1;
        while (str[i][j] == ' ')
            j++;
        if (str[i][j] != '1' || str[i][len] != '1')
            err_hand(12);
        i++;
	}
}

void    CheckTrueMap(t_cub *cub)
{
    CheckFirstLine(cub->map->TrueMap);
    CheckLastLine(cub->map->TrueMap);
    CheckWalls(cub->map->TrueMap);
    InitSide(cub);
    CheckObjects(cub);
    GetPositionPlayer(cub);
    cub->map_height = CalculeTrueMap(cub);
    CheckInsideMap(cub);
}