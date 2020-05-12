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
int 	ft_press_mana(int keycode, t_cub *cub)
{
	if (keycode ==  K_ESC)
		ft_close_pgm(cub);
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
	if (keycode == K_AR_L)
	{
		printf("");
		ft_raycasting(cub);
	}
	if (keycode == K_AR_R)
	{
		printf("lets try");
		if (cub->player.cardinal == North)
		{
			ft_AR_cam_left(cub);
			ft_cast_left_side(cub, ft_north_left_h_hit, ft_north_left_v_hit);
			ft_AR_cam_right(cub);
			ft_cast_right_side(cub, ft_north_right_h_hit, ft_north_right_v_hit);
		}
		else
		{
			printf("try again lol\n");
		}
		
	}
	return(0);
}

int		ft_restart(t_cub *cub)
{
	//mlx_clear_window(cub->mlx_ptr, cub->win.win_ptr);
	//ft_raycasting(cub);
	return (0);
}


/*
** Comms
*/
void	ft_event(t_cub *cub)
{
	//mlx_hook(cub->win.win_ptr, 3, 1L << 1, ft_close_pgm, cub);
	//mlx_hook(cub->win.win_ptr, 2, 1L << 0, ft_close_pgm, cub);
	//mlx_hook(cub->win.win_ptr, 17, 1L << 17, ft_close_pgm, cub);
	//mlx_hook(cub->win.win_ptr, 2, 1L<<0, ft_key_wads, cub);
	mlx_hook(cub->win.win_ptr, 2, 1L<<0, ft_press_mana, cub);
	//mlx_loop_hook(cub->mlx_ptr, ft_restart, cub);	
}
