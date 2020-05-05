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

void	ft_search_v_hit(double *dist, int *v, t_cub *cub, int (*ft)(t_cub *))
{
	double dist_h;
	double dist_v;

	dist_h = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor);
	while (*v == 0)
		*v = ft(cub);
	if (*v == -1)
		*dist = dist_h;
	else if (*v == 1)
	{
		dist_v = ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor);
		if (dist_h <= dist_v)
			*dist = dist_h;
		else
			*dist = dist_v;
	}
}

void	ft_search_h_hit(double *dist, int *h, t_cub *cub, int (*ft)(t_cub *))
{
	double dist_h;
	double dist_v;

	dist_v = ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor);
	while (*h == 0)
		*h = ft(cub);
	if (*h == -1)
		*dist = dist_v;
	else if (*h == 1)
	{
		dist_h = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor);
		if (dist_h <= dist_v)
			*dist = dist_h;
		else
			*dist = dist_v;
	}
}

void	ft_closer_hit(double *dist, t_cub *cub)
{
	double dist_h;
	double dist_v;

	dist_h = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor);
	dist_v = ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor);
	if (dist_h <= dist_v)
		*dist = dist_h;
	else
		*dist = dist_v;
}
