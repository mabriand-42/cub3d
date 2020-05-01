/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars.c 			                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:05:48 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/09 13:58:00 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Initialise une structure de type
** t_configuration : met à 0 la résolution,
** à NULL les textures, à -1 les couleurs,
** et en "NO" les checks de configuration.
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
** en mettant tout en "NO".
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
	c.Resolution = NO;
	c.NO_texture = NO;
	c.SO_texture = NO;
	c.WE_texture = NO;
	c.EA_texture = NO;
	c.S_texture = NO;
	c.Ceiling_color = NO;
	c.Floor_color = NO;
	*check = c;
}

/*
** Initialise une structure de type t_map
** en mettant les deux versions de la carte
** (1D et 2D) à NULL, le statut de la première
** ligne de la map en "NO" et celui de la
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
	m.first = NO;
	m.cardinal = Not_given;
	*map = m;
}

/*
** Coms
*/

void    ft_init_parse_struct(t_pars_data *ptr)
{
    ft_init_config(&(ptr->config));
	ft_init_map(&(ptr->map));
    ptr->save = NO;
}
