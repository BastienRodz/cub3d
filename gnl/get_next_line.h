/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barodrig <barodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:20:49 by barodrig          #+#    #+#             */
/*   Updated: 2021/03/02 20:29:44 by barodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin2(char const *s1, char const *s2);
int		ft_return(char *str);
int		get_next_line(int fd, char **line);

#endif
