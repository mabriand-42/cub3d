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

void	ft_get_draw_data(t_cub *cub, double d_to_wall)
{
	int		slice;

	slice = ft_scale(cub->player.dist_to_plane, d_to_wall);
	cub->draw.ceiling.x = 0;
	cub->draw.ceiling.y = ((cub->player.plane.y) / 2) - (slice / 2) - 1;
	cub->draw.floor.x = ((cub->player.plane.y) / 2) + (slice / 2);
	cub->draw.floor.y = cub->player.plane.y - 1;
	cub->draw.wall.x = cub->draw.ceiling.y + 1;
	cub->draw.wall.y = cub->draw.floor.x - 1;
	cub->draw.C_rgb = ft_create_color(cub->draw.C.R,
						cub->draw.C.G, cub->draw.C.B);
	cub->draw.F_rgb = ft_create_color(cub->draw.F.R,
						cub->draw.F.G, cub->draw.F.B);
}

void	ft_draw_pxl_line(t_cub *cub, double d_to_wall)
{
	int i;
	int j;
	int	color_wall;

	i = cub->draw.i;
	j = cub->draw.j;
	ft_init_draw(cub);
	ft_get_draw_data(cub, d_to_wall);
	if (cub->cast.wall == North)
	{
		color_wall = ft_create_color(166, 255, 0);
	}
	else if (cub->cast.wall == South)
	{
		color_wall = ft_create_color(193, 173, 220);
	}
	else if (cub->cast.wall == West)
	{
		color_wall = ft_create_color(166, 255, 0);
	}
	else if (cub->cast.wall == East)
	{
		color_wall = ft_create_color(193, 3, 220);
	}
	else
	{
		color_wall = ft_create_color(78, 235, 0);
	}
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

void	ft_draw_left_rays(t_cub *cub)
{
	double	dist;

	cub->draw.j = 0;
	ft_affine(cub, NO);
	dist = ft_search_wall(cub, ft_left_h_hit, ft_left_v_hit);
	ft_draw_pxl_line(cub, dist);
	ft_new_angle(cub);
	(cub->draw.i)++;
}

void	ft_draw_right_rays(t_cub *cub)
{
	double	dist;

	cub->draw.j = 0;
	ft_affine(cub, YES);
	dist = ft_search_wall(cub, ft_right_h_hit, ft_right_v_hit);
	ft_draw_pxl_line(cub, dist);
	ft_new_angle(cub);
	(cub->draw.i)--;
}
