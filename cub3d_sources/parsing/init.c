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

#include "../../cub3d_header/cub3d.h"

/*
** Initialise une structure de type
** t_configuration : met à 0 la résolution,
** à NULL les textures, à -1 les couleurs,
** et en "Empty" les checks de configuration.
** =========
** #1 : un pointeur sur une t_configuration.
** =========
*/

void	ft_init_config(t_config *config)
{
	t_config c;

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

/*
** Initialise une structure de type t_check
** en mettant tout en "Empty".
** (Une telle structure à pour vocation d'être
** modifiée au cours du parsing afin de suivre
** la récupération des données de configuration).
** =========
** #1 : un pointeur sur un t_check.
** =========
*/

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

/*
** Initialise une structure de type t_map
** en mettant les deux versions de la carte
** (1D et 2D) à NULL, le statut de la première
** ligne de la map en "Empty" et celui de la
** position du joueur en "Not_given".
** =========
** #1 : un pointeur sur une t_map.
** =========
*/

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

/*
** Actualise la position du joueur,
** en fonction du caractère donné.
** =========
** #1 : un caractère 'N', 'S', 'E' ou 'W'.
** #2 : un pointeur sur une t_map.
** =========
*/

void	ft_update_player(char c, t_map *m)
{
	t_map m_2;

	m_2 = *m;
	if (c == 'N')
		m_2.player = North;
	if (c == 'S')
		m_2.player = South;
	if (c == 'E')
		m_2.player = East;
	if (c == 'W')
		m_2.player = West;
	*m = m_2;
}
