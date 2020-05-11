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

/*
** Coms
*/

double	ft_deg_to_rad(double degree)
{
	double	radian;

	radian = (degree / 2) * (PI / 180);
	return (radian);
}

/*
** Coms
*/

int		ft_scale(double d_to_plane, double d_to_wall)
{
	double	d_wall;
	int		i_wall;

	d_wall = (2.25 / d_to_wall) * d_to_plane;
	i_wall = (int)round(d_wall);
	return (i_wall);
}

/*
** Coms
*/

void	ft_new_angle(t_cub *cub, t_bool right)
{
	cub->cast.angle.degree -= (cub->cast.step.degree);
	cub->cast.angle.radian = ft_deg_to_rad(cub->cast.angle.degree);
	if (right == NO)
	{
		cub->cast.left_d_screen = (cub->player.dist_to_plane) *
							sin(cub->cast.angle.radian) /
							cos(cub->cast.angle.radian);
	}
	if (right == YES)
	{
		cub->cast.right_d_screen = (cub->player.dist_to_plane) *
							sin(cub->cast.angle.radian) /
							cos(cub->cast.angle.radian);
	}
	cub->cast.first_H = NO;
	cub->cast.first_V = NO;
}

/*
** Coms
*/

int		ft_create_color(int r, int g, int b)
{
	return ((256 * 256 * r) + (256 * g) + b);
}

/*
** Coms
*/

size_t	ft_column_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
