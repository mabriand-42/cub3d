/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:43:28 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/09 13:17:39 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_path(char *line, size_t *pos, char **path)
{
	//int		ret;
	char	*p;

	p = *path;
	//ret = 0;
	if (ft_isspace(line[*pos]) == 1)
	{
		ft_reinit_buffer(*pos, line);
		p = strdup(line);
		*path = p;
		return (1);
	}
	return (0);
}

int	ft_get_t_info(char *line, size_t *pos, char **path, t_bool *check)
{
	size_t	position;
	char	*texture;
	t_bool	check_2;

	position = *pos;
	texture = *path;
	check_2 = *check;
	position++;
	if ((ft_path(line, &position, &texture) == 1) && (check_2 == Empty))
	{
		check_2 = Filled;
		*pos = position;
		*path = texture;
		*check = check_2;
		return (1);
	}
	return (0);
}
