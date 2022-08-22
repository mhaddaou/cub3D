/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 03:34:28 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/22 06:03:48 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
