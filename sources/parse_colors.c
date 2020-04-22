/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:51:47 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/04 16:24:08 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*
** Convertit une partie d'une chaîne de caractères
** afin de récupèrer une intensité colorimétrique.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** =========
** Retourne un entier positif compris entre 0 et 255,
** -1 en cas d'erreur.
*/

int	ft_color(char *line, size_t *pos)
{
	int param;
	int ret;

	param = 0;
	ret = -1;
	if (ft_isspace(line[*pos]) == 1)
		ft_skip_spaces(line, pos);
	else
		return (-1);
	if (ft_isdigit(line[*pos]))
	{
		while (ft_isdigit(line[*pos]) == 1)
		{
			param = (param * 10) + line[*pos] - 48;
			(*pos)++;
		}
		if (param >= 0 && param <= 255)
			ret = param;
	}
	return (ret);
}

/*
** Récupère, à l'aide de ft_color(2) les valeurs RGB
** d'une couleur, vérifie qu'elles sont correctement
** séparées, et les affecte aux champs correspondant
** d'une stucture c de type t_color.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : un pointeur sur une t_color.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int	ft_rgb(char *line, size_t *pos, t_color *c)
{
	t_color	c_2;
	int		ret;

	c_2 = *c;
	ret = 0;
	if ((c_2.R = ft_color(line, pos)) != -1)
	{
		if ((line[(*pos)++] == ',') && (c_2.G = ft_color(line, pos)) != -1)
		{
			if ((line[(*pos)++] == ',') && (c_2.B = ft_color(line, pos)) != -1)
			{
				*c = c_2;
				ret = 1;
			}
		}
	}
	return (ret);
}

/*
** Récupère les valeurs RGB d'une couleur
** puis vérifie leur validité ainsi que celle
** du check correspondant et actualise ce dernier
** en "Filled" si tout est OK.
** =========
** #1 : une chaîne de caractères
**		(correspond à la ligne lue par GNL).
** #2 : un pointeur sur une position dans cette chaîne.
** #3 : un pointeur sur une t_color.
** #4 : un pointeur sur un t_bool.
** =========
** Retourne 0 en cas d'erreur, 1 si tout est OK.
*/

int	ft_cf(char *line, size_t *pos, t_color *color, t_bool *check)
{
	size_t	position;
	t_color	c;
	t_bool	check_2;

	position = *pos;
	c = *color;
	check_2 = *check;
	if ((ft_rgb(line, &position, &c) == 1) && (check_2 == Empty))
	{
		check_2 = Filled;
		*pos = position;
		*color = c;
		*check = check_2;
		return (1);
	}
	return (0);
}
