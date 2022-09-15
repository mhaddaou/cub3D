/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:16:50 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/14 18:53:31 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

char	*ft_strncpy(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	checkcolorrange(int r)
{
	if (r < 0 || r > 255)
		err_hand2(11);
}

void	checkcolor(char *str)
{
	int	i;

	i = 0;
	if (!(*str))
		err_hand(0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			err_hand2(13);
		i++;
	}
	checkcolorrange(ft_atoi(str));
}

void	free_and_exit(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map->map[i])
	{
		free(cub->map->map[i]);
		i++;
	}
	free(cub->map->map);
	cub->map->map = NULL;
	i = 0;
	while (cub->map->truemap[i])
	{
		free(cub->map->truemap[i]);
		i++;
	}
	free(cub->map->truemap);
	cub->map->truemap = NULL;
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
}
