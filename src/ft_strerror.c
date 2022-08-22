/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 05:38:08 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/08/22 05:39:00 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub3d.h"

void ft_strerror(int err)
{
    if (err == 1)
        ft_putstr_fd("Error\nThe extension of the map is not correct.\n", 2);
}