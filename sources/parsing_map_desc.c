/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_desc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:13:57 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 09:56:57 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isvalidchar(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == ' ' || c == 'N' || c == 'S' 
	|| c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	ft_cmp_char(char c1, char c2, t_map *map)
{
	t_map m;

	m = *map;
	if (ft_isvalidchar(c1) == 0 || ft_isvalidchar(c2) == 0)
		return (0);
	if (c1 == 'N')
		m.player = North;
	if (c1 == 'S')
		m.player = South;
	if (c1 == 'E')
		m.player = East;
	if (c1 == 'W')
		m.player = West;
	if (c1 == ' '
		&& (c2 == '0' || c2 == '2' || c2 == 'N' || c2 == 'S' || c2 == 'E' || c2 == 'W'))
		return (0);
	else if (c1 == '0' && c2 == ' ')
		return (0);
	else if (c1 == '2' && c2 == ' ')
		return (0);
	else if ((c1 == 'N' || c1 == 'S' || c1 == 'E' || c1 == 'W')
			&& (c2 == 'N' || c2 == 'S' || c2 == 'E' || c2 == 'W' || c2 == ' '))
		return (0);
	else
	{
		*map = m;
		return (1);
	}
}

int	ft_cmp_prev_next(char c1, char *line, size_t index)
{
	size_t i_next;
	size_t i_prev;
	char c2;
	char c3;

	i_next = index + 1;
	i_prev = index - 1;
	c2 = line[i_prev];
	c3 = line[i_next];

	if (c1 == ' ' && ((c2 == '0' || c2 == '2' || c2 == 'N' || c2 == 'S' || c2 == 'E' || c2 == 'W' )
		|| (c3 == '0' || c3 == '2'|| c3 == 'N' || c3 == 'S' || c3 == 'E' || c3 == 'W')))
		return (0);
	else if (c1 == '0' && (c2 == ' ' || c3 == ' '))
		return (0);
	else if (c1 == '2' && (c2 == ' ' || c2 == ' '))
		return (0);
	else if ((c1 == 'N' || c1 == 'S' || c1 == 'E' || c1 == 'W')
		&& ((c2 == ' ' || c2 == 'N' || c2 == 'S' || c2 == 'E' || c2 == 'W')
		|| (c3 == ' ' || c3 == 'N' || c3 == 'S' || c3 == 'E' || c3 == 'W')))
		return (0);
	return (1);
}


int	ft_check_rest_line(char *line, size_t *pos)
{
	while(line[*pos] != '\0')
	{
		if (line[*pos] == '1' || line[*pos] == ' ')
			(*pos)++;
		else
			return(0);
	}
	return (1);
}

int	ft_duo_line(char *prev, char *next, t_map *map)
{
	size_t i;
	size_t j;
	int ret;
	int ret2;

	i = 0;
	j = 0;
	ret = 0;
	ret2 = 0;
	while (prev[i] != '\0' && next[j] != '\0')
	{
		if ((ret = ft_cmp_char(prev[i], next[j], map)) == 1)
		{
			if ((ret2 = ft_cmp_prev_next(next[i], prev, j) == 1))
			{
				i++;
				j++;
			}
			else
				return(0);
		}
		else if ((ret = ft_cmp_char(prev[i], next[j], map)) == 0)
			break;
	}
	if (prev[i] == '\0' && next[j] == '\0')
	{
		if (prev[i - 1] != '1' || next[i - 1] != '1')
			return (0);
		return (1);
	}
	else if (prev[i] != '\0' && next[j] != '\0')
		return (0);
	else if (prev[i] == '\0' && next[j] != '\0')
		return(ft_check_rest_line(next, &j));
	else if (prev[i] != '\0' && next[j] == '\0')
		return(ft_check_rest_line(prev, &i));
	else
		return (0);
}

int	ft_check_isolated_line(char *line)
{
	size_t i;
	//int ret;

	i = 0;
	//ret = 0;
	if (ft_check_rest_line(line, &i) == 1)
		return (1);
	return (0);
}
