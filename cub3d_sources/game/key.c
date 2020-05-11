/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
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
void	ft_init_move(t_move *move)
{
	move->W =  NO;
	move->S =  NO;
	move->A =  NO;
	move->D =  NO;
	move->AL =  NO;
	move->AR =  NO;
}
/*
** Comms
*/
int		ft_key_press(int keycode, t_move *move)
{
	if (keycode == K_W)
		move->W =  YES;
	if (keycode == K_S)
		move->S =  YES;
	if (keycode == K_A)
		move->A =  YES;
	if (keycode == K_D)
		move->D =  YES;
	if (keycode == K_AR_L)
		move->AL =  YES;
	if (keycode == K_AR_R)
		move->AR =  YES;
	return (0);
}
/*
** Comms
*/
int		ft_key_release(int keycode, t_move *move)
{
	if (keycode == K_W)
		move->W =  NO;
	if (keycode == K_S)
		move->S =  NO;
	if (keycode == K_A)
		move->A =  NO;
	if (keycode == K_D)
		move->D =  NO;
	if (keycode == K_AR_L)
		move->AL =  NO;
	if (keycode == K_AR_R)
		move->AR =  NO;
	return (0);
}
/*
** Comms
*/
