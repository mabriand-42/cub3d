/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:06:00 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:18:25 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		main(void)
{
	int				fd;
	int				ret_gnl;
	char			*str;
	char *next;
	t_map 			map;
	t_config	config;

	fd = open("./sources/test_mlx.cub", O_RDONLY);
	ret_gnl = 1;
	str = NULL;
	next = NULL;
	ft_init_config(&config);
	ft_init_map (&map);
	while (ret_gnl > 0)
	{
		ret_gnl = gnl(fd, &str);
		if (ft_orient_gnl(ret_gnl, &map, &config, str, next) == 0)
			return (0);
		next = ft_strdup(str);
		free(str);
	}
	if (map.player == Not_given)
		return(0);
	int i = 0;
	while (map.two_d[i] != NULL)
	{
		printf("%s\n", map.two_d[i]);
		i++;
	}
	/*
	printf("=======RESOLUTION=====\n");
	printf("%zu\n", config.R.x);
	printf("%zu\n", config.R.y);
	printf("=======NO_PATH========\n");
	printf("%s\n", config.T.path_NO);
	printf("=======SO_PATH========\n");
	printf("%s\n", config.T.path_SO);
	printf("=======WE_PATH========\n");
	printf("%s\n", config.T.path_WE);
	printf("=======EA_PATH========\n");
	printf("%s\n", config.T.path_EA);
	printf("=======S_PATH=========\n");
	printf("%s\n", config.T.path_S);
	printf("=======GROUND COLOR===\n");
 	printf("%d\n", config.F.R);
	printf("%d\n", config.F.G);
	printf("%d\n", config.F.B);
	printf("=======CEILING COLOR==\n");
	printf("%d\n", config.C.R);
	printf("%d\n", config.C.G);
	printf("%d\n", config.C.B);
	printf("=======MAP DESCRIPTION\n");
	printf("%s\n", map.map);
	printf("=======PLAYER POS=====\n");
	printf("%d\n", map.player);
	system("leaks a.out");
	//while (1)
	//	;*/
	return (0);
}