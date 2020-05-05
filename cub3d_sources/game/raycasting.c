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
	cub->cast.angle = cub->player.fov;
	cub->cast.step = cub->player.step;
	cub->cast.delta_screen = cub->player.mid_x;
	cub->cast.affine.a = 0;
	cub->cast.affine.b = 0;
	cub->cast.wall_hit = NO;
	cub->cast.ray = 0;
	cub->cast.first_H = NO;
	cub->cast.first_V = NO;
}

void	ft_cast_side(t_cub *cub, void (*ft)(t_cub *),
					int (*ft_h)(t_cub *), int (*ft_v)(t_cub *))
{
	ft_init_cast(cub);
	while (cub->cast.angle.degree >= cub->cast.step.degree)
	{
		ft(cub);
		ft_search_wall(cub, ft_h, ft_v);
		cub->cast.angle.degree -= (cub->cast.step.degree);
		cub->cast.angle.radian = ft_deg_to_rad(cub->cast.angle.degree);
		cub->cast.delta_screen = (cub->player.dist_to_plane) *
								sin(cub->cast.angle.radian) /
								cos(cub->cast.angle.radian);
		cub->cast.first_H = NO;
		cub->cast.first_V = NO;
	}
}

int		ft_raycasting(t_cub *cub)
{
	ft_cast_side(cub, ft_left_affine, ft_left_h_hit, ft_left_v_hit);
	ft_search_wall_cp(cub);
	ft_cast_side(cub, ft_right_affine, ft_right_h_hit, ft_right_v_hit);
	return (1);
}
