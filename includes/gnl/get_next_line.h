/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <izail@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:23:44 by izail             #+#    #+#             */
/*   Updated: 2022/09/16 18:59:50 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include "../libft/libft.h"
# define BUFFER_SIZE (10)

// int		ft_strlen(char *str);
// char	*ft_strdup(char *s1);
// char	*ft_strjoin(char *s1, char *s2);

// char	*ft_gnl_get_begin(char *str);
// char	*ft_gnl_get_end(char *str);
// char	*gnl_output_without_bn(char **str, int read_return);
// char	*gnl_without_bn(int fd);
char	*get_next_line(int fd);

#endif
