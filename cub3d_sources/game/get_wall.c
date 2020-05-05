/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

double	ft_search_wall(t_cub *cub, int (*ft_h)(t_cub *), int (*ft_v)(t_cub *))
{
	double	dist;
	int		h;
	int		v;

	dist = 0;
	h = 0;
	v = 0;
	while (h == 0 || v == 0)
	{
		h = ft_h(cub);
		v = ft_v(cub);
		if ((h == 1 && v == 0) || (h == 1 && v == -1))
			ft_search_v_hit(&dist, &v, cub, ft_v);
		else if ((h == 0 && v == 1) || (h == -1 && v == 1))
			ft_search_h_hit(&dist, &v, cub, ft_h);
		else if (h == 1 && v == 1)
			ft_closer_hit(&dist, cub);
	}
	return (dist);
}

double	ft_search_wall_cp(t_cub *cub)
{
	double	dist;
	int		h_bound;

	dist = 0;
	h_bound = 0;
	while (h_bound == 0)
	{
		h_bound = ft_left_h_hit(cub);
		if (h_bound == 1)
			dist = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor, cub);
	}
	return (dist);
}
