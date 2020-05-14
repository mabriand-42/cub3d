/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Comms
*/

void	ft_move(t_cub *cub, void (*ft_n)(t_cub *),
							void (*ft_s)(t_cub *),
							void (*ft_w)(t_cub *),
							void (*ft_e)(t_cub *))
{
	if (cub->player.cardinal == North)
		ft_n(cub);
	if (cub->player.cardinal == South)
		ft_s(cub);
	if (cub->player.cardinal == West)
		ft_w(cub);
	if (cub->player.cardinal == East)
		ft_e(cub);
	cub->player.dist_to_plane = ft_dist_to_plane(cub);
}

/*
** Comms
*/

void	ft_x_plus(t_cub *cub)
{
	t_coor	coor_swap;

	coor_swap = cub->player.coor;
	ft_init_player(cub);
	cub->player.coor.x = coor_swap.x + STEP_MOVE;
	cub->player.coor.y = coor_swap.y;
	cub->player.box.x = (int)floor(cub->player.coor.x);
	cub->player.box.y = (int)floor(cub->player.coor.y);
	cub->player.mid_x = (double)cub->player.plane.x / 2.0;
	if (cub->box_map[cub->player.box.y][cub->player.box.x] == '1')
	{
		cub->player.coor.x -= STEP_MOVE;
		cub->player.box.x = (int)floor(cub->player.coor.x);
	}
}

/*
** Comms
*/

void	ft_x_minus(t_cub *cub)
{
	t_coor	coor_swap;

	coor_swap = cub->player.coor;
	ft_init_player(cub);
	cub->player.coor.x = coor_swap.x - STEP_MOVE;
	cub->player.coor.y = coor_swap.y;
	cub->player.box.x = (int)floor(cub->player.coor.x);
	cub->player.box.y = (int)floor(cub->player.coor.y);
	cub->player.mid_x = (double)cub->player.plane.x / 2.0;
	if (cub->box_map[cub->player.box.y][cub->player.box.x] == '1')
	{
		cub->player.coor.x += STEP_MOVE;
		cub->player.box.x = (int)floor(cub->player.coor.x);
	}
}

/*
** Comms
*/

void	ft_y_plus(t_cub *cub)
{
	t_coor	coor_swap;

	coor_swap = cub->player.coor;
	ft_init_player(cub);
	cub->player.coor.x = coor_swap.x;
	cub->player.coor.y = coor_swap.y + STEP_MOVE;
	cub->player.box.x = (int)floor(cub->player.coor.x);
	cub->player.box.y = (int)floor(cub->player.coor.y);
	cub->player.mid_x = (double)cub->player.plane.x / 2.0;
	if (cub->box_map[cub->player.box.y][cub->player.box.x] == '1')
	{
		cub->player.coor.y -= STEP_MOVE;
		cub->player.box.y = (int)floor(cub->player.coor.y);
	}
}

/*
** Comms
*/

void	ft_y_minus(t_cub *cub)
{
	t_coor	coor_swap;

	coor_swap = cub->player.coor;
	ft_init_player(cub);
	cub->player.coor.x = coor_swap.x;
	cub->player.coor.y = coor_swap.y - STEP_MOVE;
	cub->player.box.x = (int)floor(cub->player.coor.x);
	cub->player.box.y = (int)floor(cub->player.coor.y);
	cub->player.mid_x = (double)cub->player.plane.x / 2.0;
	if (cub->box_map[cub->player.box.y][cub->player.box.x] == '1')
	{
		cub->player.coor.y += STEP_MOVE;
		cub->player.box.y = (int)floor(cub->player.coor.y);
	}
}
