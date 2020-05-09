/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall.c                                         :+:      :+:    :+:   */
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

double	ft_search_wall(t_cub *cub, int (*ft_h)(t_cub *), int (*ft_v)(t_cub *))
{
	double	dist;
	int		h;
	int		v;

	dist = 0;
	h = 0;
	v = 0;
	cub->cast.wall = Not_given;
	while (h == 0 || v == 0)
	{
		h = ft_h(cub);
		v = ft_v(cub);
		if ((h == 1 && v == 0) || (h == 1 && v == -1))
			ft_search_v_hit(&dist, &v, cub, ft_v);
		else if ((h == 0 && v == 1) || (h == -1 && v == 1))
			ft_search_h_hit(&dist, &v, cub, ft_h);
		else if (h == 1 && v == 1)
		{
			ft_closer(&dist, cub, ft_hypotenuse(cub->player.coor,
					cub->cast.ray_h.coor, cub), ft_hypotenuse(cub->player.coor,
					cub->cast.ray_v.coor, cub));
		}
	}
	return (dist);
}

/*
** Coms
*/

void	ft_v_wall_orient(t_cub *cub, double coor_x, int box_y)
{
	t_box	box;

	box.x = (int)coor_x;
	box.y = box_y;
	if (cub->box_map[box.y][box.x] == '1')
		cub->cast.wall = West;
	else
	{
		if (cub->box_map[box.y][box.x - 1] == '1')
			cub->cast.wall = East;
	}
}

/*
** Coms
*/

void	ft_h_wall_orient(t_cub *cub, double coor_y, int box_x)
{
	t_box	box;

	box.x = box_x;
	box.y = (int)coor_y;
	if (cub->box_map[box.y][box.x] == '1')
		cub->cast.wall = North;
	else
	{
		if (cub->box_map[box.y - 1][box.x] == '1')
			cub->cast.wall = South;
	}
}
