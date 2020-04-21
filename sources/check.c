/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:16:11 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:05:17 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

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
	if (check.Resolution == Empty)
		return (0);
	if (check.NO_texture == Empty)
		return (0);
	if (check.SO_texture == Empty)
		return (0);
	if (check.WE_texture == Empty)
		return (0);
	if (check.EA_texture == Empty)
		return (0);
	if (check.S_texture == Empty)
		return (0);
	if (check.Ceiling_color == Empty)
		return (0);
	if (check.Ground_color == Empty)
		return (0);
	return (1);
}