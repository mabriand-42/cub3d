/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
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

void	ft_init_cast(t_cub *cub)
{
	cub->cast.ray_h.box.x = 0;
	cub->cast.ray_h.box.y = 0;
	cub->cast.ray_h.coor.x = 0;
	cub->cast.ray_h.coor.y = 0;
	cub->cast.ray_v.box.x = 0;
	cub->cast.ray_v.box.y = 0;
	cub->cast.ray_v.coor.x = 0;
	cub->cast.ray_v.coor.y = 0;
	cub->cast.left_angle = cub->player.left_angle;
	cub->cast.right_angle = cub->player.right_angle;
	cub->cast.step = cub->player.step;
	cub->cast.left_d_screen =
		ft_opposite(cub->player.dist_to_plane, cub->cast.left_angle);
	cub->cast.right_d_screen =
		ft_opposite(cub->player.dist_to_plane, cub->cast.right_angle);
	cub->cast.affine.a = 0;
	cub->cast.affine.b = 0;
	cub->cast.wall_hit = NO;
	cub->cast.first_H = NO;
	cub->cast.first_V = NO;
	cub->cast.wall = Not_given;
}

/*
** Coms
*/

void	ft_cast_left_side(t_cub *cub,
			int (*ft_lh)(t_cub *), int (*ft_lv)(t_cub *))
{
	cub->draw.i = 0;
	ft_init_cast(cub);
	while (cub->cast.left_angle.degree > cub->cast.bound.degree)
		ft_draw_left(cub, ft_lh, ft_lv);
}

/*
** Coms
*/

void	ft_cast_right_side(t_cub *cub,
			int (*ft_rh)(t_cub *), int (*ft_rv)(t_cub *))
{
	cub->draw.i = cub->player.plane.x - 1;
	ft_init_cast(cub);
	while (cub->cast.left_angle.degree > cub->cast.bound.degree)
		ft_draw_right(cub, ft_rh, ft_rv);
}

/*
** Coms
*/

void	ft_raycasting(t_cub *cub)
{
	if (cub->player.cardinal == North)
	{
		ft_cast_left_side(cub, ft_north_left_h_hit, ft_north_left_v_hit);
		ft_cast_right_side(cub, ft_north_right_h_hit, ft_north_right_v_hit);
	}
	else if (cub->player.cardinal == South)
	{
		ft_cast_left_side(cub, ft_south_left_h_hit, ft_south_left_v_hit);
		ft_cast_right_side(cub, ft_south_right_h_hit, ft_south_right_v_hit);
	}
	else if (cub->player.cardinal == West)
	{
		ft_cast_left_side(cub, ft_south_right_h_hit, ft_south_right_v_hit);
		ft_cast_right_side(cub, ft_north_left_h_hit, ft_north_left_v_hit);
	}
	else if (cub->player.cardinal == East)
	{
		ft_cast_left_side(cub, ft_north_right_h_hit, ft_north_right_v_hit);
		ft_cast_right_side(cub, ft_south_left_h_hit, ft_south_left_v_hit);
	}
}
