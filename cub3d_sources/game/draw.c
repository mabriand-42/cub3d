/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
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

void	ft_init_draw(t_cub *cub)
{
	cub->draw.C_rgb = -1;
	cub->draw.F_rgb = -1;
	cub->draw.ceiling.x = -1;
	cub->draw.ceiling.y = -1;
	cub->draw.floor.x = -1;
	cub->draw.floor.y = -1;
	cub->draw.wall.x = -1;
	cub->draw.wall.y = -1;
}

/*
** Coms
*/

void	ft_get_draw_data(t_cub *cub, double d_to_wall)
{
	int		slice;

	slice = ft_scale(cub->player.dist_to_plane, d_to_wall);
	cub->draw.ceiling.x = 0;
	cub->draw.ceiling.y = ((cub->player.plane.y) / 2) - (slice / 2) - 1;
	cub->draw.floor.x = ((cub->player.plane.y) / 2) + (slice / 2);
	cub->draw.floor.y = cub->player.plane.y - 1;
	cub->draw.wall.x = abs(cub->draw.ceiling.y + 1);
	cub->draw.wall.y = abs(cub->draw.floor.x - 1);
	cub->draw.C_rgb = ft_create_color(cub->draw.C.R,
						cub->draw.C.G, cub->draw.C.B);
	cub->draw.F_rgb = ft_create_color(cub->draw.F.R,
						cub->draw.F.G, cub->draw.F.B);
}

/*
** Coms
*/

void	ft_draw_pxl_line(t_cub *cub, double d_to_wall)
{
	int i;
	int j;
	int	color_wall;

	i = cub->draw.i;
	j = cub->draw.j;
	ft_init_draw(cub);
	ft_get_draw_data(cub, d_to_wall);
	color_wall = ft_get_wall_color(cub);
	while (j <= cub->draw.ceiling.y)
	{
		mlx_pixel_put(cub->mlx_ptr, cub->win.win_ptr, i, j, cub->draw.C_rgb);
		j++;
	}
	while (j <= cub->draw.wall.y)
	{
		mlx_pixel_put(cub->mlx_ptr, cub->win.win_ptr, i, j, color_wall);
		j++;
	}
	while (j <= cub->draw.floor.y)
	{
		mlx_pixel_put(cub->mlx_ptr, cub->win.win_ptr, i, j, cub->draw.F_rgb);
		j++;
	}
}

/*
** Coms
*/

void	ft_draw_left(t_cub *cub, int (*ft_lh)(t_cub *), int (*ft_lv)(t_cub *))
{
	double	dist;

	cub->draw.j = 0;
	ft_affine(cub, NO);
	dist = ft_search_wall(cub, ft_lh, ft_lv);
	ft_draw_pxl_line(cub, dist);
	ft_new_angle_minus(cub, NO);
	(cub->draw.i)++;
}

/*
** Coms
*/

void	ft_draw_right(t_cub *cub, int (*ft_rh)(t_cub *), int (*ft_rv)(t_cub *))
{
	double	dist;

	cub->draw.j = 0;
	ft_affine(cub, YES);
	dist = ft_search_wall(cub, ft_rh, ft_rv);
	ft_draw_pxl_line(cub, dist);
	ft_new_angle_minus(cub, YES);
	(cub->draw.i)--;
}
