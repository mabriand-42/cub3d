/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

/*
** Vérifie que le format du fichier donné grâce à son
** chemin correspond à celui attendu.
** =========
** #1 : un format de fichier.
** #2 : le chemin vers le fichier donné.
** =========
** Retourne 1 si le format correspond, 0 sinon.
*/

int		ft_file_type(const char *type, const char *fd_path)
{
	size_t	i;
	size_t	j;

	if (type[0] != '.' || (type == NULL || fd_path == NULL))
		return (0);
	i = ft_strlen(type);
	j = ft_strlen(fd_path);
	if (i >= j)
		return (0);
	while (i > 0)
	{
		if (type[i] != fd_path[j])
			return (0);
		i--;
		j--;
	}
	if (type[i] == fd_path[j])
		return (1);
	return (0);
}

/*
** Vérifie que les arguments donnés à main()
** sont valides et actualise le statut du champ
** save du t_cub si besoin.
** =========
** #1 : (= argc)
** #2 : (= argv)
** #3 : un pointeur sur un t_cub.
** =========
** Retourne 1 si tout est OK, 0 sinon.
*/

int		ft_check_arg(int ac, char **av, t_pars_data *ptr)
{
	if (ac < 2 || ac > 3 || ft_file_type(".cub", av[1]) == 0)
		return (0);
	if (ac == 3)
	{
		if (ft_strcmp("--save", av[2]) != 0)
			return (0);
		ptr->save = YES;
	}
	return (1);
}

/*
** Coms
*/

void	ft_equivalent_data(t_pars_data *pars_data, t_cub *cub)
{
	cub->save = pars_data->save;
	cub->win.R = pars_data->config.R;
	cub->img.R = pars_data->config.R;
	cub->text.path = pars_data->config.T;
	cub->box_map = pars_data->map.two_d;
	cub->player.plane = pars_data->config.R;
	cub->player.cardinal = pars_data->map.cardinal;
	cub->player.mid_x = (double)pars_data->config.R.x / 2.0;
	cub->draw.C = pars_data->config.C;
	cub->draw.F = pars_data->config.F;
}

/*
** Coms
*/

int		ft_pre_start(t_pars_data *pars_data, t_cub *cub, int ac, char **av)
{
	int	ret_check_arg;
	int	ret_parse;

	ft_init_parse_struct(pars_data);
	ret_check_arg = ft_check_arg(ac, av, pars_data);
	if (ret_check_arg == 0)
	{
		printf("ERROR : please check ARGUMENT(S)\n\n");
		return (0);
	}
	ret_parse = ft_parse_fd(av[1], pars_data);
	if (ret_parse == 0)
	{
		printf("ERROR : please check FILE\n\n");
		return (0);
	}
	ft_equivalent_data(pars_data, cub);
	return (1);
}
