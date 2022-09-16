/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:48:17 by izail             #+#    #+#             */
/*   Updated: 2021/11/20 03:34:15 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_elm;

	if (!lst)
		return (NULL);
	last_elm = lst;
	while (last_elm->next)
		last_elm = last_elm->next;
	return (last_elm);
}
