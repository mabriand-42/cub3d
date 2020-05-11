/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:01:23 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:10:28 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_header/cub3d.h"

int     main(int argc, char **argv)
{
    t_pars_data pars_data;
    t_cub       cub;
    int         ret_ray;
    if(ft_pre_start(&pars_data, &cub, argc, argv) == 0)
    {
        printf("ERROR : seems like cub3d did not even try to load!\n\n");
        return(0);
    }
	int	ret_player = ft_get_player_data(&cub);
	if (ret_player == 0)
	{
        printf("ERROR : probleme in player data!\n\n");
        return(0);
    }
	ret_ray = ft_start(&cub);
    if (ret_ray == 0)
    {
        printf("ERROR : please check RAYCASTING\n\n");
        return (0);
    }
    system("leaks a.out");
    return(0);
}

    /*printf("=======RESOLUTION=====\n");
	printf("%d\n", pars_data.config.R.x);
	printf("%d\n", pars_data.config.R.y);
	printf("=======NO_PATH========\n");
	printf("%s\n", pars_data.config.T.path_NO);
	printf("=======SO_PATH========\n");
	printf("%s\n", pars_data.config.T.path_SO);
	printf("=======WE_PATH========\n");
	printf("%s\n", pars_data.config.T.path_WE);
	printf("=======EA_PATH========\n");
	printf("%s\n", pars_data.config.T.path_EA);
	printf("=======S_PATH=========\n");
	printf("%s\n", pars_data.config.T.path_S);
	printf("=======FLOOR COLOR====\n");
 	printf("%d\n", pars_data.config.F.R);
	printf("%d\n", pars_data.config.F.G);
	printf("%d\n", pars_data.config.F.B);
	printf("=======CEILING COLOR==\n");
	printf("%d\n", pars_data.config.C.R);
	printf("%d\n", pars_data.config.C.G);
	printf("%d\n", pars_data.config.C.B);
	printf("=======MAP DESCRIPTION\n");
	printf("%s\n", pars_data.map.map);
	printf("=======PLAYER POS=====\n");
	printf("%d\n", pars_data.map.cardinal);*/
	
    /*i = 0;
	while ((pars_data.map.two_d[i]) != NULL)
	{
		printf("%s\n", pars_data.map.two_d[i]);
		i++;
	}*/
