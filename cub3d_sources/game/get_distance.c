/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Coms
*/

void	ft_search_v_hit(double *dist, int *v, t_cub *cub, int (*ft)(t_cub *))
{
	double dist_h;
	double dist_v;

	dist_h = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor, cub);
	while (*v == 0)
		*v = ft(cub);
	if (*v == -1)
	{
		*dist = dist_h;
		ft_h_wall_orient(cub, cub->cast.ray_h.coor.y, cub->cast.ray_h.box.x);
	}
	else if (*v == 1)
	{
		dist_v = ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor, cub);
		ft_closer(dist, cub, dist_h, dist_v);
	}
}

/*
** Coms
*/

void	ft_search_h_hit(double *dist, int *h, t_cub *cub, int (*ft)(t_cub *))
{
	double dist_h;
	double dist_v;

	dist_v = ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor, cub);
	while (*h == 0)
		*h = ft(cub);
	if (*h == -1)
	{
		*dist = dist_v;
		ft_v_wall_orient(cub, cub->cast.ray_v.coor.x, cub->cast.ray_v.box.y);
	}
	else if (*h == 1)
	{
		dist_h = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor, cub);
		ft_closer(dist, cub, dist_h, dist_v);
	}
}

/*
** Coms
*/

void	ft_closer(double *dist, t_cub *cub, double dist_h, double dist_v)
{
	if (dist_h <= dist_v)
	{
		*dist = dist_h;
		ft_h_wall_orient(cub, cub->cast.ray_h.coor.y, cub->cast.ray_h.box.x);
	}
	else
	{
		*dist = dist_v;
		ft_v_wall_orient(cub, cub->cast.ray_v.coor.x, cub->cast.ray_v.box.y);
	}
}
