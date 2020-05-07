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
	cub->cast.angle.degree = cub->player.fov.degree / 2;
	cub->cast.angle.radian = cub->player.fov.radian / 2;
	cub->cast.step = cub->player.step;
	cub->cast.delta_screen = cub->player.mid_x;
	cub->cast.affine.a = 0;
	cub->cast.affine.b = 0;
	cub->cast.wall_hit = NO;
	//cub->cast.ray = 0;
	cub->cast.first_H = NO;
	cub->cast.first_V = NO;
	cub->cast.wall = Not_given; //
}

void	ft_cast_left_side(t_cub *cub)
{
	cub->draw.i = 0;
	ft_init_cast(cub);
	while (cub->draw.i < cub->player.mid_x)
		ft_draw_left_rays(cub);
}

void	ft_cast_right_side(t_cub *cub)
{
	double	dist;

	cub->draw.i = cub->player.plane.x - 1;
	ft_init_cast(cub);
	if ((cub->player.plane.x % 2) == 0)
		cub->player.mid_x -= 1;
	while (cub->draw.i > cub->player.mid_x)
		ft_draw_right_rays(cub);
}

void	ft_raycasting(t_cub *cub)
{
	ft_cast_left_side(cub);
	ft_cast_right_side(cub);
}
