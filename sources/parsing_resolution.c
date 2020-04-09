/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:52:12 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/04 16:19:25 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_r(char *line, size_t *pos, t_resolution *resolution, t_bool *check)
{
	size_t			position;
	t_resolution	r;
	t_bool			check_2;

	position = *pos;
	r = *resolution;
	check_2 = *check;
	if ((ft_resolution(line, &position, &r) == 1) && (check_2 == Empty))
	{
		check_2 = Filled;
		*pos = position;
		*resolution = r;
		*check = check_2;
		return (1);
	}
	return (0);
}

int	ft_resolution(char *line, size_t *pos, t_resolution *R)
{
	t_resolution r;
	int ret;

	r = *R;
	ret = 0;
	if ((r.x = ft_get_r_info(line, pos)) != 0)
	{
		if ((r.y = ft_get_r_info(line, pos)) != 0)
		{
			*R = r;
			ret = 1;
		}
	}
	return (ret);
}

size_t	ft_get_r_info(char *line, size_t *pos)
{
	size_t param;

	param = 0;
	if (ft_isspace(line[*pos]) == 1)
		ft_skip_spaces(line, pos);
	else
		return (0);
	if (ft_isdigit(line[*pos]) == 1)
	{
		while (ft_isdigit(line[*pos]) == 1)
		{
			param = (param * 10) + line[*pos] - 48;
			(*pos)++;
		}
	}
	return (param);
}