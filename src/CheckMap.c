/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:47:34 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/29 16:07:36 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int CheckEmptyLine(char *line)
{
    if (!ft_strncmp(line, "\n", ft_strlen(line)))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

void CheckShortNameTwo(t_map *map, char *str, int i, int j)
{
    if (!ft_strncmp(str, "EA", ft_strlen(str)))
    {
        GetInfo(map, 'E');
        map->e++;   
    }
    else if (!ft_strncmp(str, "F", ft_strlen(str)))
    {
        GetInfo(map, 'F');
        map->f++;    
    }
    else if (!ft_strncmp(str, "C", ft_strlen(str)))
    {
        GetInfo(map, 'C');
        map->c++; 
    }
    else
        err_hand(5);
}


void    CheckShortName(t_map *map,char *str, int i, int j)
{
    map->i = i;
    map->j = j;
    if (!ft_strncmp(str, "NO", ft_strlen(str)))
    {
        GetInfo(map,'N');
        map->n++;
    }
    else if (!ft_strncmp(str, "SO", ft_strlen(str)))
    {
        GetInfo(map, 'S');
        map->s++;   
    }
    else if (!ft_strncmp(str, "WE", ft_strlen(str)))
    {
        GetInfo(map, 'W');
        map->w++;   
    }
    else
        CheckShortNameTwo(map,str,i,j);
}
    

void check_line(t_map *map,int  i)
{
    int j;
    int index;
    
    index = 0;
    j = 0;
    char ar[BUFFER_SIZE];
    if (CheckEmptyLine(map->map[i]) == EXIT_FAILURE)
        return ;
    while (map->map[i][j] == ' ' || map->map[i][j] == '\t')
        j++;
    while (map->map[i][j] != ' ' && map->map[i][j] != '\t')
    {
        ar[index] = map->map[i][j];
        j++;
        index++;
    }
    ar[index] = '\0';
    CheckShortName(map, ar,i, j+1);
}
void CheckEmptyPath(t_map *map)
{
    if (!*map->Ntexture)
		err_hand(8);
    if (!*map->Stexture)
		err_hand(8);
    if (!*map->Wtexture)
		err_hand(8);
    if (!*map->Etexture)
		err_hand(8);
}

t_map    *CheckMap(t_map *map)
{
    int i;

    i = 0;
    while (map->map[i] && map->check != 6)
    {
        check_line(map, i);
        i++;
    }
    if (CheckNoSoEaFC(map) == EXIT_FAILURE)
        err_hand(6);
    map->check = i;
    ft_free1(map);
    return (map);
}