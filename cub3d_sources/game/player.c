/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

void	ft_init_player(t_cub *cub)
{
	cub->player.box.x = 0;
	cub->player.box.y = 0;
	cub->player.coor.x = 0;
	cub->player.coor.y = 0;
	cub->player.dir.vect_x = 0;
	cub->player.dir.vect_y = 0;
	cub->player.coor.x = 0;
	cub->player.coor.y = 0;
	cub->player.dist_to_plane = 0;
	cub->player.fov.degree = FOV;
	cub->player.fov.radian = ft_deg_to_rad(FOV);
	cub->player.step.degree = (FOV / cub->player.plane.x);
	cub->player.step.radian = ft_deg_to_rad(cub->player.step.degree);
	//mid et tout ???
}

int		ft_iscardinal(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	ft_get_player_dir(t_cub *cub, char c)
{
	if (c == 'N')
	{
		cub->player.dir.vect_x = 0;
		cub->player.dir.vect_y = -1;
	}
	if (c == 'S')
	{
		cub->player.dir.vect_x = 0;
		cub->player.dir.vect_y = 1;
	}
	if (c == 'W')
	{
		cub->player.dir.vect_x = -1;
		cub->player.dir.vect_y = 0;
	}
	if (c == 'E')
	{
		cub->player.dir.vect_x = 1;
		cub->player.dir.vect_y = 0;
	}
}

int		ft_get_player_pos(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->box_map[i] != NULL)
	{
		j = 0;
		while (cub->box_map[i][j] != '\0')
		{
			if (ft_iscardinal(cub->box_map[i][j]) == 1)
			{
				ft_get_player_dir(cub, cub->box_map[i][j]);
				cub->player.box.x = j;
				cub->player.box.y = i;
				cub->player.coor.x = j + 0.5;
				cub->player.coor.y = i + 0.5;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_get_player_data(t_cub *cub)
{
	ft_init_player(cub);
	if (ft_get_player_pos(cub) == 0)
		return (0);
	cub->player.dist_to_plane = ft_dist_to_plane(cub);
	return (1);
}
