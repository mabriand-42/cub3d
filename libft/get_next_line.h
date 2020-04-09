/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:27:21 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/02 11:36:02 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include "libft/libft.h"

/*
** STRUCURE
*/

/*
** PROTOTYPE
*/
int			get_next_line(int fd, char **line);
//size_t	ft_strlen(char *s);
//char		*ft_strjoin(char *s1, char *s2);
ssize_t		ft_search_line(char *s);
//char		*ft_strdup(char *s1);
char		*ft_strndup(char *s1, size_t size);
void		ft_reinit_buffer(ssize_t start, char *buffer);
char		*ft_create_line(char *str, char **line);
// char		*ft_strcpy(char *dest, char *src);

#endif
