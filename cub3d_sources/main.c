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

#include "../cub3d_header/cub3d.h"

int		main(void)
{
	/*int			fd;
	int			ret_gnl;
	t_duo		duo;
	t_map 		m;
	t_config	c;

	fd = open("./cub3d_sources/test_mlx.cub", O_RDONLY);
	ret_gnl = 1;
	duo.line = NULL;
	duo.prev = NULL;
	ft_init_config(&c);
	ft_init_map (&m);
	while (ret_gnl > 0)
	{
		ret_gnl = gnl(fd, &duo.line);
		if (ft_orient_gnl(ret_gnl, &m, &c, duo) == 0)
			return (0);
		duo.prev = ft_strdup(duo.line);
		free(duo.line);
	}
	if (m.player == Not_given)
		return(0);
	int i = 0;
	while (m.two_d[i] != NULL)
	{
		printf("%s\n", m.two_d[i]);
		i++;
	}
	
	printf("=======RESOLUTION=====\n");
	printf("%zu\n", c.R.x);
	printf("%zu\n", c.R.y);
	printf("=======NO_PATH========\n");
	printf("%s\n", c.T.path_NO);
	printf("=======SO_PATH========\n");
	printf("%s\n", c.T.path_SO);
	printf("=======WE_PATH========\n");
	printf("%s\n", c.T.path_WE);
	printf("=======EA_PATH========\n");
	printf("%s\n", c.T.path_EA);
	printf("=======S_PATH=========\n");
	printf("%s\n", c.T.path_S);
	printf("=======GROUND COLOR===\n");
 	printf("%d\n", c.F.R);
	printf("%d\n", c.F.G);
	printf("%d\n", c.F.B);
	printf("=======CEILING COLOR==\n");
	printf("%d\n", c.C.R);
	printf("%d\n", c.C.G);
	printf("%d\n", c.C.B);
	printf("=======MAP DESCRIPTION\n");
	printf("%s\n", m.map);
	printf("=======PLAYER POS=====\n");
	printf("%d\n", m.player);
	system("leaks a.out");
	//while (1)
	//
	return (0);*/
}