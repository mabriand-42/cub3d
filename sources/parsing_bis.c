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

int		ft_get_config(char *id, char *line, size_t *pos, t_config *c)
{
	if (ft_strcmp(id, "R") == 0)
		return (ft_r(line, pos, &(c->R), &(c->check.Resolution)));
	else if (ft_strcmp(id, "NO") == 0)
		return (ft_t(line, pos, &(c->T.path_NO), &(c->check.NO_texture)));
	else if (ft_strcmp(id, "SO") == 0)
		return (ft_t(line, pos, &(c->T.path_SO), &(c->check.SO_texture)));
	else if (ft_strcmp(id, "WE") == 0)
		return (ft_t(line, pos, &(c->T.path_WE), &(c->check.WE_texture)));
	else if (ft_strcmp(id, "EA") == 0)
		return (ft_t(line, pos, &(c->T.path_EA), &(c->check.EA_texture)));
	else if (ft_strcmp(id, "S") == 0)
	{
		(*pos)--;
		return (ft_t(line, pos, &(c->T.path_S), &(c->check.S_texture)));
	}
	else if (ft_strcmp(id, "F") == 0)
		return (ft_cf(line, pos, &(c->F), &(c->check.Ground_color)));
	else if (ft_strcmp(id, "C") == 0)
		return (ft_cf(line, pos, &(c->F), &(c->check.Ceiling_color)));
	return (0);
}
