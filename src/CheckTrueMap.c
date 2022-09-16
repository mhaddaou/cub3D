/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTrueMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:16:41 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/16 22:35:48 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_first_line(char **str)
{
	int	i;

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
		if ((str[0][i] == '1' && str[0][i + 1] == '\0') && str[1][i + 1] == '0')
			err_hand(9);
		i++;
	}
}

void	check_last_line(char **str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	len--;
	while (str[len][i])
	{
		if (str[len][i] == ' ' )
			if (str[len - 1][i] != ' ' && str[len - 1][i] != '1')
				err_hand2(10);
		if (str[len][i] == ' ' && str[1][i] == '1')
			if (str[len - 1][i + 1] != '1')
				err_hand2(10);
		if (str[len][i] != '1' && str[len][i] != ' ')
			err_hand2(10);
		if ((str[len][i] == '1' && str[len][i + 1] == '\0')
		&& str[len - 1][i + 1] == '0')
			err_hand2(10);
		i++;
	}
}

void	check_walls(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = 0;
	while (str[i])
	{
		j = 0;
		len = ft_strlen(str[i]) - 1;
		while (str[i][j] == ' ')
			j++;
		if (str[i][j] != '1' || str[i][len] != '1')
			err_hand2(12);
		i++;
	}
}

void check_is_empty(char **str)
{
	if (!str)
		printf("ahh\n");
}


void	check_true_map(t_cub *cub)
{
	check_is_empty(cub->map->truemap);
	check_first_line(cub->map->truemap);
	check_last_line(cub->map->truemap);
	check_walls(cub->map->truemap);
	init_side(cub);
	check_objects(cub);
	get_position_player(cub);
	cub->map_height = calcule_true_map(cub);
	check_inside_map(cub);
	ft_mlx(cub);
}
