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

#include "../header/cub3d.h"

/*
** Si un indentier est trouvé en début de ligne,
** la fonction le compare à ceux de la liste donnée et oriente
** la suite du parsing en fonction de la correspondance trouvée.
** =========
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : un pointeur vers une t_configuration.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

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
	if (ft_find_id(line, identifier, &pos) == 1)
	{
		if (ft_strcmp(identifier, "R") == 0)
			ret = ft_r(line, &pos, &c.R, &c.check.Resolution);
		else if (ft_strcmp(identifier, "NO") == 0)
			ret = ft_t(line, &pos, &c.T.path_NO, &c.check.NO_texture);
		else if (ft_strcmp(identifier, "SO") == 0)
			ret = ft_t(line, &pos, &c.T.path_SO, &c.check.SO_texture);
		else if (ft_strcmp(identifier, "WE") == 0)
			ret = ft_t(line, &pos, &c.T.path_WE, &c.check.WE_texture);
		else if (ft_strcmp(identifier, "EA") == 0)
			ret = ft_t(line, &pos, &c.T.path_EA, &c.check.EA_texture);
		else if (ft_strcmp(identifier, "S") == 0)
		{
			pos--;
			ret = ft_t(line, &pos, &c.T.path_S, &c.check.S_texture);
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

/*
** Vérifie la validité des lignes décrivant la map et crée
** une version 1D de celle-ci.
** =========
** #1 : le retour de GNL.
** #2 : un pointeur sur une t_map.
** #3 : un pointeur sur une t_configuration.
** #4 : la chaîne de caractères actuelle (lue par GNL).
** #5 : la chaîne de caractères précédente (lue par GNL).
** =========
** Retourne 1 si tout est OK, 0 sinon.
*/ 

int	ft_orient_gnl(int ret_gnl, t_map *map, t_configuration *config, char *str, char *prev)
{
	t_map			map_2;
	t_configuration	config_2;
	char			*line;
	int				ret_elem_parsing;

	map_2 = *map;
	config_2 = *config;
	line = ft_strdup(str);
	ret_elem_parsing = ft_elem_parsing(line, &config_2);
	if (ret_gnl == 0)
	{
		if (ft_check_isolated_line(line) == 0
		|| ((ft_check_isolated_line(line) == 1) && (ft_lines(line, prev, &map_2, &config_2) == 0)))
			return (0);
		ft_transform_map(&map_2);
	}
	else
	{
		if (ret_elem_parsing == 1)
			free(prev);
		else if ((ret_elem_parsing == 0)
		|| ((ret_elem_parsing == -1) && (ft_lines(line, prev, &map_2, &config_2) == 0)))
			return (0);
	}
	*map = map_2;
	*config = config_2;
	free(line);
	return (1);
}