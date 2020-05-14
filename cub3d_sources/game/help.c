/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
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

int		ft_get_wall_color(t_cub *cub)
{
	if (cub->cast.wall == North)
		return (ft_create_color(69, 231, 160));
	else if (cub->cast.wall == South)
		return (ft_create_color(193, 173, 220));
	else if (cub->cast.wall == West)
		return (ft_create_color(166, 255, 0));
	else if (cub->cast.wall == East)
		return (ft_create_color(231, 83, 69));
	else
		return (ft_create_color(78, 235, 0));
}
