/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
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

int	ft_start(t_cub *cub)
{
	cub->done = YES;
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((cub->win.win_ptr = mlx_new_window(cub->mlx_ptr,
		cub->win.R.x, cub->win.R.y, "test")) == NULL)
		return (0);
	ft_raycasting(cub);
	mlx_loop(cub->mlx_ptr);
	return (1);
}
