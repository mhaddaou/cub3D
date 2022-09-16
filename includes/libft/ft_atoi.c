/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:58:58 by izail             #+#    #+#             */
/*   Updated: 2021/11/24 04:17:22 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			signe;
	long		nbr;

	signe = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		signe = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * signe);
}
