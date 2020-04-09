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


#include "cub3d.h"


int	ft_check_identifier(char c1, char c2)
{
	if ((c1 == 'N' && c2 == 'O') || (c1 == 'W' && c2 == 'E') || (c1 == 'E' && c2 == 'A'))
		return (1);
	return (0);
}


int	ft_is_identifier(char *line, char *identifier, size_t *pos)
{
	char *letters_0;
	char *letters_1;
	char *letters_2;

	letters_0 = "RFC";
	letters_1 = "NWE";
	letters_2 = "OEA";
	if (ft_is_in_string(line[*pos], letters_0) == 1)
	{
		(*pos)++;
		if (ft_isspace(line[*pos]) == 1)
		{
			identifier = ft_strncpy(identifier, line, 1);
			return (1);
		}
	}
	else if (ft_is_in_string(line[*pos], letters_1) == 1)
	{
		(*pos)++;
		if (ft_isspace(line[*pos]) == 0 || ft_is_in_string(line[*pos], letters_2) == 1)
		{
			if (ft_check_identifier(line[*pos - 1] , line[*pos]) == 1)
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