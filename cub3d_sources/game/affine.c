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
	if (right == NO)
	{
		if (cub->player.cardinal == West || cub->player.cardinal == East)
			a = -(cub->cast.left_d_screen) / (cub->player.dist_to_plane);
		else
			a = (cub->player.dist_to_plane) / (cub->cast.left_d_screen);
	}
	if (right == YES)
	{
		if (cub->player.cardinal == West || cub->player.cardinal == East)
			a = (cub->cast.right_d_screen) / (cub->player.dist_to_plane);
		else
			a = -(cub->player.dist_to_plane) / (cub->cast.right_d_screen);
	}
	b = y - (a * x);
	cub->cast.affine.a = a;
	cub->cast.affine.b = b;
	printf("a : %f\n", cub->cast.affine.a);
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
	dist_to_wall = cos(cub->cast.left_angle.radian) *
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
	double	dist_to_plane;

	dist_to_plane = cub->player.mid_x / tan(cub->player.fov.radian);
	return (dist_to_plane);
}

/*
**
*/
double	ft_opposite(double dist_to_plane, t_angle angle)
{
	double opposite;

	opposite = tan(angle.radian) * dist_to_plane;
	return (opposite);
}