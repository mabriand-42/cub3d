/*fonctions à enlever plus tard, pratique juste pour aider à la construction*/


#include "../../cub3d_header/cub3d.h"

/*
** Coms
*/

int		ft_get_wall_color(t_cub *cub)
{
	if (cub->cast.wall == North)
		return (ft_create_color(69, 231, 160));
	else if (cub->cast.wall == South)
		return (ft_create_color(193, 173, 220));
	else if (cub->cast.wall == West)
		return (ft_create_color(166, 255, 0));
	else if (cub->cast.wall == East)
		return (ft_create_color(231, 83, 69));
	else
		return (ft_create_color(78, 235, 0));
}