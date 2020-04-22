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

#include "../header/cub3d.h"

/*
** Récupère une partie d'une chaîne de caractères
** correspondant à un path vers une texture.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : l'adresse d'une chaîne de caractères
**		(correspondant un path contenu dans
**		une t_configuration et initialisé à NULL
**		en début de parsing).
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int	ft_path(char *line, size_t *pos, char **path)
{
	char	*path_2;

	path_2 = *path;
	if (ft_isspace(line[*pos]) == 1)
	{
		ft_reinit_buffer(*pos, line);
		path_2 = strdup(line);
		*path = path_2;
		return (1);
	}
	return (0);
}

/*
** Récupère le path vers une texture, vérifie
** la validité du check correspondant et actualise
** ce dernier en "Filled" si tout est OK.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : un pointeur sur une t_resolution.
** #4 : un pointeur sur un t_bool.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int	ft_t(char *line, size_t *pos, char **path, t_bool *check)
{
	size_t	pos_2;
	char	*path_2;
	t_bool	check_2;

	pos_2 = *pos;
	path_2 = *path;
	check_2 = *check;
	pos_2++;
	if ((ft_path(line, &pos_2, &path_2) == 1) && (check_2 == Empty))
	{
		check_2 = Filled;
		*pos = pos_2;
		*path = path_2;
		*check = check_2;
		return (1);
	}
	return (0);
}
