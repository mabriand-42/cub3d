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

#include "cub3d.h"

int	ft_cf(char *line, size_t *pos, t_color *color, t_bool *check)
{
	size_t	position;
	t_color	c;
	t_bool	check_2;

	position = *pos;
	c = *color;
	check_2 = *check;
	if ((ft_color(line, &position, &c) == 1) && (check_2 == Empty))
	{
		check_2 = Filled;
		*pos = position;
		*color = c;
		*check = check_2;
		return (1);
	}
	return (0);
}

int	ft_color(char *line, size_t *pos, t_color *C)
{
	t_color c;
	int ret;

	c = *C;
	ret = 0;
	if ((c.R = ft_get_cf_info(line, pos)) != -1)
	{
		if ((line[(*pos)++] == ',') && (c.G = ft_get_cf_info(line, pos)) != -1)
		{
			if ((line[(*pos)++] == ',') && (c.B = ft_get_cf_info(line, pos)) != -1)
			{
				*C = c;
				ret = 1;
			}
		}
	}
	return (ret);
}

int	ft_get_cf_info(char *line, size_t *pos)
{
	int param;
	int ret;

	param = 0;
	ret = -1;
	if (ft_isspace(line[*pos]) == 1)
		ft_skip_spaces(line, pos);
	else
		return (0);
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


