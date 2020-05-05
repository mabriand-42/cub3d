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

void	ft_new_angle(t_cub *cub)
{
	cub->cast.angle.degree -= (cub->cast.step.degree);
	cub->cast.angle.radian = ft_deg_to_rad(cub->cast.angle.degree);
	cub->cast.delta_screen = (cub->player.dist_to_plane) *
							sin(cub->cast.angle.radian) /
							cos(cub->cast.angle.radian);
	cub->cast.first_H = NO;
	cub->cast.first_V = NO;
}


void	ft_cast_left_side(t_cub *cub)
{
	double	dist;

	cub->draw.i = 0;
	ft_init_cast(cub);
	while (cub->cast.angle.degree >= cub->cast.step.degree)
	//(cub->draw.i < cub->player.mid_x) 
	//(cub->cast.angle.degree >= cub->cast.step.degree)
	{
		printf("test");
		cub->draw.j = 0;
		ft_left_affine(cub);
		dist = ft_search_wall(cub, ft_left_h_hit, ft_left_v_hit);
		ft_draw_pxl_line(cub, dist, cub->draw.i);
		ft_new_angle(cub);
		(cub->draw.i)++;
	}
}


void	ft_cast_right_side(t_cub *cub)
{
	double	dist;

	cub->draw.i = cub->player.plane.x - 1;
	ft_init_cast(cub);
	while (cub->cast.angle.degree >= cub->cast.step.degree)
	{
		printf("TEST");
		cub->draw.j = 0;
		ft_right_affine(cub);
		dist = ft_search_wall(cub, ft_right_h_hit, ft_right_v_hit);
		ft_draw_pxl_line(cub, dist, cub->draw.i);
		ft_new_angle(cub);
		(cub->draw.i)--;	
	}
}

void	ft_cast_middle(t_cub *cub)
{
	double	dist;

	dist = ft_search_wall_cp(cub);
	ft_draw_pxl_line(cub, dist, cub->draw.i);
}

void	ft_raycasting(t_cub *cub)
{
	ft_cast_left_side(cub);
	ft_cast_middle(cub);
	ft_cast_right_side(cub);
}