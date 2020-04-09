/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:48:08 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/09 13:55:02 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_elem_parsing(char *line, t_configuration *config)
{
	t_configuration	c;
	size_t			pos;
	char			*identifier;
	int				ret;

	c = *config;
	pos = 0;
	ret = -1;
	if(!(identifier = (char *)malloc(sizeof(char) * 3)))
		return (ret);
	if (ft_is_identifier(line, identifier, &pos) == 1)
	{
		if (ft_strcmp(identifier, "R") == 0)
			ret = ft_r(line, &pos, &c.R, &c.check.Resolution);
		else if (ft_strcmp(identifier, "NO") == 0)
			ret = ft_get_t_info(line, &pos, &c.T.path_NO, &c.check.NO_texture);
		else if (ft_strcmp(identifier, "SO") == 0)
			ret = ft_get_t_info(line, &pos, &c.T.path_SO, &c.check.SO_texture);
		else if (ft_strcmp(identifier, "WE") == 0)
			ret = ft_get_t_info(line, &pos, &c.T.path_WE, &c.check.WE_texture);
		else if (ft_strcmp(identifier, "EA") == 0)
			ret = ft_get_t_info(line, &pos, &c.T.path_EA, &c.check.EA_texture);
		else if (ft_strcmp(identifier, "S") == 0)
		{
			pos--;
			ret = ft_get_t_info(line, &pos, &c.T.path_S, &c.check.S_texture);
		}
		else if (ft_strcmp(identifier, "F") == 0)
			ret = ft_cf(line, &pos, &c.F, &c.check.Ground_color);
		else if (ft_strcmp(identifier, "C") == 0)
			ret = ft_cf(line, &pos, &c.C, &c.check.Ceiling_color);
	}
	else if (line[0] == '\0')
		ret = 1;
	free(identifier);
	*config = c;
	return (ret);
}