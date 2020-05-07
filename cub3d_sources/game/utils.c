/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

double	ft_deg_to_rad(double degree)
{
	double	radian;

	radian = (degree / 2) * (PI / 180);
	return (radian);
}

int		ft_scale(double d_to_plane, double d_to_wall)
{
	double	d_wall;
	int		i_wall;

	d_wall = (2.25 / d_to_wall) * d_to_plane; // je comprends pas pk 2.25
	i_wall = (int)round(d_wall);
	return (i_wall);
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

int		ft_create_color(int r, int g, int b)
{
	return ((256 * 256 * r) + (256 * g) + b);
}
