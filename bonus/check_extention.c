/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 03:34:28 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/09/18 00:12:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	check_extension(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (file_name[len - 4] == '.')
		if (file_name[len - 3] == 'c')
			if (file_name[len - 2] == 'u')
				if (file_name[len - 1] == 'b')
					return (0);
	return (-1);
}
