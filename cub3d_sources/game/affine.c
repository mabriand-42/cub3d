/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Calcule le coefficient directeur et
** l'ordonnée à l'origine d'une fonction
** affine (inversée selon le côté du FOV).
** =========
** #1 : un pointeur sur un t_cub.
** =========
*/

void	ft_affine(t_cub *cub, t_bool right)
{
	double x;
	double y;
	double a;
	double b;

	x = cub->player.coor.x;
	y = cub->player.coor.y;
	a = (cub->player.dist_to_plane) / (cub->cast.delta_screen);
	if (right == YES)
		a = -a;
	b = y - (a * x);
	cub->cast.affine.a = a;
	cub->cast.affine.b = b;
}

/*
** Calcul l'hypoténuse d'un triangle rectangle,
** correspondant à la distance entre le joueur et
** le point d'intersection du rayon lancé et d'un mur.
** =========
** #1 : la positon (x,y) du joueur.
** #2 : les coordonnées de l'intersection du rayon lancé
**      et d'un mur.
** =========
** Retourne la distance obtenue.
*/

double	ft_hypotenuse(t_coor start, t_coor new, t_cub *cub)
{
	double	delta_x;
	double	delta_y;
	double	dist_to_wall;

	delta_x = fabs(start.x - new.x);
	delta_y = fabs(start.y - new.y);
	dist_to_wall = cos(cub->cast.angle.radian) *
					sqrt((delta_x * delta_x) + (delta_y * delta_y));
	return (dist_to_wall);
}

/*
** Calcul la distance entre le joueur et le milieu
** du plan de projection.
** =========
** #1 : un pointeur sur un t_cub.
** =========
** Retourne la distance obtenue.
*/

double	ft_dist_to_plane(t_cub *cub)
{
	double	mid_x;
	double	radian;
	double	dist_to_plane;

	mid_x = cub->player.mid_x;
	radian = cub->player.fov.radian;
	dist_to_plane = mid_x / tan(radian);
	return (dist_to_plane);
}
