/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:02:07 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/22 06:02:32 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != NULL)
			free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (map)
		free(map);
	map = NULL;
}
