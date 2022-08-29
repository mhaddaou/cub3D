/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckMapTwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:41:49 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/29 09:45:41 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int    CheckNoSoEaFC(t_map *map)
{
    if (map->n == 1)
        if (map->s == 1)
            if (map->e == 1)
                if (map->f == 1)
                    if (map->c == 1)
                        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}