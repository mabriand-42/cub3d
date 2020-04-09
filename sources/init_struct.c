/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:16:11 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:05:17 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_config(t_configuration *config)
{
	t_configuration c;

	c = *config;
	c.R.x = 0;
	c.R.y = 0;
	c.T.path_NO = NULL;
	c.T.path_SO = NULL;
	c.T.path_WE = NULL;
	c.T.path_EA = NULL;
	c.T.path_S = NULL;
	c.C.R = -1;
	c.C.R = -1;
	c.C.G = -1;
	c.C.B = -1;
	c.F.R = -1;
	c.F.G = -1;
	c.F.B = -1;
	ft_init_check(&c.check);
	*config = c;
}

void	ft_init_check(t_check *check)
{
	t_check	c;

	c = *check;
	c.Resolution = Empty;
	c.NO_texture = Empty;
	c.SO_texture = Empty;
	c.WE_texture = Empty;
	c.EA_texture = Empty;
	c.S_texture = Empty;
	c.Ceiling_color = Empty;
	c.Ground_color = Empty;
	*check = c;
}

void	ft_init_map(t_map *map)
{
	t_map m;
	
	m = *map;
	m.map = NULL;
	m.two_d = NULL;
	m.first = Empty;
	m.player = Not_given;
	*map = m;
}

int		ft_is_config_full(t_check check)
{
	if (check.Resolution == Empty)
		return (0);
	if (check.NO_texture == Empty)
		return (0);
	if (check.SO_texture == Empty)
		return (0);
	if (check.WE_texture == Empty)
		return (0);
	if (check.EA_texture == Empty)
		return (0);
	if (check.S_texture == Empty)
		return (0);
	if (check.Ceiling_color == Empty)
		return (0);
	if (check.Ground_color == Empty)
		return (0);
	return (1);
}


