/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   south_wall_hit.c                                   :+:      :+:    :+:   */
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

int	ft_south_left_h_hit(t_cub *cub)
{
	double	a;
	double	b;
	size_t	len_x;

	a = cub->cast.affine.a;
	b = cub->cast.affine.b;
	if (cub->cast.first_H == NO)
	{
		cub->cast.ray_h.coor.y = ceil(cub->player.coor.y);
		cub->cast.first_H = YES;
	}
	len_x = ft_strlen(cub->box_map[(int)cub->cast.ray_h.coor.y]);
	cub->cast.ray_h.coor.x = ((cub->cast.ray_h.coor.y) - b) / a;
	if (cub->cast.ray_h.coor.x >= (double)len_x)
		return (-1);
	cub->cast.ray_h.box.x = (int)floor(cub->cast.ray_h.coor.x);
	cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.y);
	if (cub->box_map[cub->cast.ray_h.box.y][cub->cast.ray_h.box.x] == '1')
		return (1);
	cub->cast.ray_h.coor.y += 1;
	return (0);
}

/*
** Coms
*/

int	ft_south_left_v_hit(t_cub *cub)
{
	double	a;
	double	b;
	size_t	len_y;

	a = cub->cast.affine.a;
	b = cub->cast.affine.b;
	if (cub->cast.first_V == NO)
	{
		cub->cast.ray_v.coor.x = ceil(cub->player.coor.x);
		cub->cast.first_V = YES;
	}
	len_y = ft_column_len(cub->box_map);
	cub->cast.ray_v.coor.y = (a * (cub->cast.ray_v.coor.x)) + b;
	if (cub->cast.ray_v.coor.y >= (double)len_y)
		return (-1);
	cub->cast.ray_v.box.x = (int)(cub->cast.ray_v.coor.x);
	cub->cast.ray_v.box.y = (int)floor(cub->cast.ray_v.coor.y);
	if (cub->box_map[cub->cast.ray_v.box.y][cub->cast.ray_v.box.x] == '1')
		return (1);
	cub->cast.ray_v.coor.x += 1;
	return (0);
}

/*
** Coms
*/

int	ft_south_right_h_hit(t_cub *cub)
{
	double	a;
	double	b;
	size_t	len_y;

	a = cub->cast.affine.a;
	b = cub->cast.affine.b;
	if (cub->cast.first_H == NO)
	{
		cub->cast.ray_h.coor.y = ceil(cub->player.coor.y);
		cub->cast.first_H = YES;
	}
	len_y = ft_column_len(cub->box_map);
	cub->cast.ray_h.coor.x = ((cub->cast.ray_h.coor.y) - b) / a;
	if (cub->cast.ray_h.coor.x < 0)
		return (-1);
	cub->cast.ray_h.box.x = (int)floor(cub->cast.ray_h.coor.x);
	cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.y);
	if (cub->box_map[cub->cast.ray_h.box.y][cub->cast.ray_h.box.x] == '1')
		return (1);
	cub->cast.ray_h.coor.y += 1;
	return (0);
}

/*
** Coms
*/

int	ft_south_right_v_hit(t_cub *cub)
{
	double	a;
	double	b;
	size_t	len_y;

	a = cub->cast.affine.a;
	b = cub->cast.affine.b;
	if (cub->cast.first_V == NO)
	{
		cub->cast.ray_v.coor.x = floor(cub->player.coor.x);
		cub->cast.first_V = YES;
	}
	len_y = ft_column_len(cub->box_map);
	cub->cast.ray_v.coor.y = (a * (cub->cast.ray_v.coor.x)) + b;
	if (cub->cast.ray_v.coor.y > (double)len_y)
		return (-1);
	cub->cast.ray_v.box.x = (int)(cub->cast.ray_v.coor.x) - 1;
	cub->cast.ray_v.box.y = (int)floor(cub->cast.ray_v.coor.y);
	if (cub->box_map[cub->cast.ray_v.box.y][cub->cast.ray_v.box.x] == '1')
		return (1);
	cub->cast.ray_v.coor.x -= 1;
	return (0);
}
