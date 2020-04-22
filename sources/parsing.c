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

int	ft_elem_parsing(char *line, t_config *c)
{
	t_config	c_2;
	size_t		pos;
	char		*id;
	int			ret;

	c_2 = *c;
	pos = 0;
	ret = -1;
	if (!(id = (char *)malloc(sizeof(char) * 3)))
		return (ret);
	if (ft_find_id(line, id, &pos) == 1)
		ret = ft_get_config(id, line, &pos, &c_2);
	else if (line[0] == '\0')
		ret = 1;
	free(id);
	*c = c_2;
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

int	ft_orient_gnl(int ret_gnl, t_map *m, t_config *c, char *str, char *prev)
{
	t_map		m_2;
	t_config	c_2;
	char		*line;
	int			ret_ep;
	size_t 		i;

	m_2 = *m;
	c_2 = *c;
	line = ft_strdup(str);
	ret_ep = ft_elem_parsing(line, &c_2);
	i = 0;
	if (ret_gnl == 0)
	{
		if (ft_closed_map(line, &i) == 0 || ((ft_closed_map(line, &i) == 1)
		&& (ft_lines(line, prev, &m_2, &c_2) == 0)))
			return (0);
		ft_transform_map(&m_2);
	}
	else
	{
		if (ret_ep == 1)
			free(prev);
		else if ((ret_ep == 0) || ((ret_ep == -1)
		&& (ft_lines(line, prev, &m_2, &c_2) == 0)))
			return (0);
	}
	*m = m_2;
	*c = c_2;
	free(line);
	return (1);
}
