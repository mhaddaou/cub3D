/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:16:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/30 12:22:07 by izail            ###   ########.fr       */
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
        printf("%d\n", i);
        // if (str[0][i] != '1' || str[0][i] != ' ')
            // err_hand(9);
        i++;
    }
    free(str[0]);
    
}

void    CheckLastLine(char **str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (str[len])
        len++;
    // while (str[len - 1][i] == ' ')
    //     i++;
    while (str[len - 1][i])
    {
        if (str[len - 1][i] == ' ')
            if (str[len - 2][i] != ' ' &&  str[len - 2][i] != '1')
                err_hand(10);
        // if (str[len - 1][i] != ' ' && str[len - 1][i] != '1')
        //     err_hand(10);
        i++;
    }
}

void    CheckInsideMap(char **str)
{
    int i;
    int j;

    i = 0;
    while (str[i])
        i++;
    while (str[i - 1][j])
    {
        j = 0;
        while (str[i - 1][j])
        {
            if (str[i - 1][j] == ' ')
            {
                
            }
           j++; 
        }
        i++;
    }
    
}

void    CheckWalls(char **str)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    len = 0;
    while (str[i])
        i++;
    printf("first == %s\n", str[0]);
    printf("last  == %s\n", str[i - 1]);
    while (str[0][j] != '\0' && str[i - 1][j] != '\0')
    {
        if (str[0][j] == ' ')
            j++;
        if (str[0][j] != '1' || str[i - 1][j] != '1')
            err_hand(12);
        j++;
    }
    // i = 0;
    // while (str[len])
    //     len++;
    // while (str[i])
	// {
    //     if (str[i][0] == ' ')
    //         i++;
	// 	if (str[i][0] != '1' || str[i][len - 1] != '1' )
	// 		err_hand(12);
	// 	i++;
	// }
}

void    CheckTrueMap(t_cub *cub)
{
    // CheckFirstLine(cub->map->TrueMap);

    // CheckLastLine(cub->map->TrueMap);
    CheckWalls(cub->map->TrueMap);
}