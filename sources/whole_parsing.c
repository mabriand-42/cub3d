/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_join_for_map(t_map *map, char *next, int *ret)
{
	t_map	m;
	int		r;

	m = *map;
	r = *ret;
	if (m.first == Empty)
	{
		m.map = ft_strdup(next);
		m.first = Filled;
		r = 1;
	}
	else if (m.first == Filled)
	{
		m.map = ft_join_bis(m.map, "-");
		m.map = ft_join_bis(m.map, next);
		r = 1;
	}
	*map = m;
	*ret = r;
}

int		ft_lines(char *line, char *next, t_map *map, t_configuration *config)
{
	t_map			m;
	t_configuration	c;
	int				ret;

	m = *map;
	c = *config;
	ret = 0;
	if (m.first == Empty && (ft_is_config_full(c.check) == 1))
	{
		if (ft_check_isolated_line(line) == 1)
			ft_join_for_map(&m, line, &ret);
	}
	else if (m.first == Filled && (ft_is_config_full(c.check) == 1))
	{
		if (ft_duo_line(line, next, &m) == 1)
			ft_join_for_map(&m, line, &ret);
	}
	*map = m;
	*config = c;
	free(next);
	return (ret);
}

int	ft_orient_gnl(int ret_gnl, t_map *map, t_configuration *config, char *str, char *next)
{
	t_map			m;
	t_configuration	c;
	char			*line;
	int				ret_elem_parsing;

	m = *map;
	c = *config;
	line = ft_strdup(str);
	ret_elem_parsing = ft_elem_parsing(line, &c);
	if (ret_gnl == 0)
	{
		if (ft_check_isolated_line(line) == 0
		|| ((ft_check_isolated_line(line) == 1) && (ft_lines(line, next, &m, &c) == 0)))
			return (0);
		ft_transform_map(&m);
	}
	else
	{
		if (ret_elem_parsing == 1)
			free(next);
		else if ((ret_elem_parsing == 0)
		|| ((ret_elem_parsing == -1) && (ft_lines(line, next, &m, &c) == 0)))
			return (0);
	}

	*map = m;
	*config = c;
	free(line);
	return (1);
}