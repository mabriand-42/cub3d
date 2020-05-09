/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:16:11 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:05:17 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Actualise la position du joueur,
** en fonction du caractère donné.
** =========
** #1 : un caractère 'N', 'S', 'E' ou 'W'.
** #2 : un pointeur sur une t_map.
** =========
*/

int		ft_update_player(char c, t_map *m)
{
	t_map m_2;

	m_2 = *m;
	if (m_2.cardinal == Not_given)
	{
		if (c == 'N')
			m_2.cardinal = North;
		if (c == 'S')
			m_2.cardinal = South;
		if (c == 'E')
			m_2.cardinal = East;
		if (c == 'W')
			m_2.cardinal = West;
		*m = m_2;
		return (1);
		printf("cardinal OK ?\n");
	}
	else
	{
		printf("fuck yeah");
		return (0);
	}
}

/*
** Vérifie si toutes les informations de
** configuration ont été récupérées.
** =========
** #1 : un t_check.
** =========
** Retourne 0 si une des informations de
** configuration est manquante, 1 si tout est OK.
*/

int		ft_check_config(t_check check)
{
	if (check.Resolution == NO)
		return (0);
	if (check.NO_texture == NO)
		return (0);
	if (check.SO_texture == NO)
		return (0);
	if (check.WE_texture == NO)
		return (0);
	if (check.EA_texture == NO)
		return (0);
	if (check.S_texture == NO)
		return (0);
	if (check.Ceiling_color == NO)
		return (0);
	if (check.Floor_color == NO)
		return (0);
	return (1);
}
