/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Concatène next et la chaîne représentant la map en 1D
** (contenue dans le champ correspondant de la t_map passée
** en paramètre), séparant les deux chaînes par '-'.
** S'il s'agit de la première ligne de la map, la fonction
** actualise le statut correponsant en "YES" afin qu'au(x)
** prochain(s) appel(s), le deuxième bloc d'instructions soit exécuté.
** =========
** #1 : un pointeur sur une t_map.
** #2 : une chaîne de caractères.
** #3 : un pointeur sur la valeur de retour de ft_lines(4).
** =========
*/

void	ft_create_map(t_map *map, char *next, int *ret)
{
	t_map	m;
	int		r;

	m = *map;
	r = *ret;
	if (m.first == NO)
	{
		m.map = ft_strdup(next);
		m.first = YES;
		r = 1;
	}
	else if (m.first == YES)
	{
		m.map = ft_join_bis(m.map, "-");
		m.map = ft_join_bis(m.map, next);
		r = 1;
	}
	*map = m;
	*ret = r;
}

/*
** Vérifie la validité des lignes décrivant la map et crée
** une version 1D de celle-ci.
** =========
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : la chaîne de caractères précédente (lue par GNL).
** #3 : un pointeur sur une t_map.
** #4 : un pointeur sur une t_configuration.
** =========
** Retourne 1 si tout est OK, 0 sinon.
*/

int		ft_lines(char *line, char *prev, t_map *map, t_config *config)
{
	t_map		m;
	t_config	c;
	int			ret;
	size_t		i;

	m = *map;
	c = *config;
	ret = 0;
	i = 0;
	if (m.first == NO && (ft_check_config(c.check) == 1))
	{
		if (ft_closed_map(line, &i) == 1)
			ft_create_map(&m, line, &ret);
	}
	else if (m.first == YES && (ft_check_config(c.check) == 1))
	{
		if (ft_duo_line(line, prev, &m) == 1)
			ft_create_map(&m, line, &ret);
	}
	*map = m;
	*config = c;
	free(prev);
	return (ret);
}

/*
** Convertit en 2D, avec ft_split(2), une map stockée en 1D.
** =========
** #1 : un pointeur sur une t_map.
** =========
*/

void	ft_transform_map(t_map *map)
{
	t_map m;

	m = *map;
	m.two_d = ft_split(m.map, '-');
	*map = m;
}
