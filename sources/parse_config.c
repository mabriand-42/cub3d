/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:19:35 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/05 17:38:44 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/cub3d.h"

/*
** Vérifie qu'avec le premier, le deuxième caractère
** passé en argument permet de former un des identifiers suivants :
** NO, WE, EA.
** =========
** #1 : un caractère.
** #2 : le caractère suivant.
** =========
** Retourne 1 si c'est le cas, 0 sinon.
*/

int	ft_check_id(char c1, char c2)
{
	if ((c1 == 'N' && c2 == 'O') || (c1 == 'W' && c2 == 'E') || (c1 == 'E' && c2 == 'A'))
		return (1);
	return (0);
}

/*
** Vérifie si un identifier est présent en début de ligne lue, 
** en comparant ses un ou deux premiers caracères, à ceux de 
** différentes listes données. Si c'est le cas, il crée la chaîne
** correspondante à cet identifier via ft_strncpy(3).
** =========
** #1 : la chaîne de caractères actuelle (lue par GNL).
** #2 : une chaîne de caractères.
** #3 : un pointeur sur la position actuelle dans la ligne.
** =========
** Retourne 1 si c'est le cas, 0 sinon.
*/

int	ft_find_id(char *line, char *identifier, size_t *pos)
{
	char *letters_0;
	char *letters_1;
	char *letters_2;

	letters_0 = "RFC";
	letters_1 = "NWE";
	letters_2 = "OEA";
	if (ft_find_char(line[*pos], letters_0) == 1)
	{
		(*pos)++;
		if (ft_isspace(line[*pos]) == 1)
		{
			identifier = ft_strncpy(identifier, line, 1);
			return (1);
		}
	}
	else if (ft_find_char(line[*pos], letters_1) == 1)
	{
		(*pos)++;
		if (ft_isspace(line[*pos]) == 0 || ft_find_char(line[*pos], letters_2) == 1)
		{
			if (ft_check_id(line[*pos - 1] , line[*pos]) == 1)
			{
				identifier = ft_strncpy(identifier, line, 2);
				return (1);
			}
		}
	}
	else if (line[*pos] == 'S')
	{
		(*pos)++;
		if ((ft_isspace(line[*pos]) == 1))
		{
			identifier = ft_strncpy(identifier, line, 1);
			return (1);
		}
		else if (line[*pos] == 'O')
		{
			identifier = ft_strncpy(identifier, line, 2);
			return (1);
		}
	}
	return (0);
}