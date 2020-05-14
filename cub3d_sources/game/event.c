/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
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

void	ft_close_pgm(t_cub *cub)
{
	mlx_clear_window(cub->mlx_ptr, cub->win.win_ptr);
	mlx_destroy_window(cub->mlx_ptr, cub->win.win_ptr);
	exit(EXIT_SUCCESS);
}

/*
** Comms
*/

int		ft_press_mana(int keycode, t_cub *cub)
{
	if (keycode == K_ESC)
		ft_close_pgm(cub);
	if (keycode == K_W || keycode == K_A || keycode == K_S || keycode == K_D)
		ft_move_wads(keycode, cub);
	return (0);
}

/*
** Comms
*/

void	ft_move_wads(int keycode, t_cub *cub)
{
	if (keycode == K_W)
	{
		ft_move(cub, ft_y_minus, ft_y_plus, ft_x_minus, ft_x_plus);
		ft_raycasting(cub);
	}
	if (keycode == K_A)
	{
		ft_move(cub, ft_y_plus, ft_y_minus, ft_x_plus, ft_x_minus);
		ft_raycasting(cub);
	}
	if (keycode == K_S)
	{
		ft_move(cub, ft_x_minus, ft_x_plus, ft_y_plus, ft_y_minus);
		ft_raycasting(cub);
	}
	if (keycode == K_D)
	{
		ft_move(cub, ft_x_plus, ft_x_minus, ft_y_minus, ft_y_plus);
		ft_raycasting(cub);
	}
}

/*
** Comms
*/

void	ft_event(t_cub *cub)
{
	mlx_hook(cub->win.win_ptr, 2, 1L << 0, ft_press_mana, cub);
}
