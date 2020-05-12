#include "../../cub3d_header/cub3d.h"

/*
** Comms
*/

void ft_AR_cam_left(t_cub *cub)
{
	t_coor	coor_swap;
	double	rot_swap;

	coor_swap = cub->player.coor;
	rot_swap = cub->player.rot;
	ft_init_player(cub);
	cub->player.coor.x = coor_swap.x;
	cub->player.coor.y = coor_swap.y;
	cub->player.box.x = (int)floor(cub->player.coor.x);
	cub->player.box.y = (int)floor(cub->player.coor.y);
	cub->player.rot = rot_swap + STEP_ROT;


	cub->player.mid_x = (double)cub->player.plane.x / 2.0;
	cub->player.dist_to_plane = ft_dist_to_plane(cub);

	cub->player.left_angle.degree -= (cub->player.step.degree * cub->player.rot);
	cub->player.left_angle.radian = ft_deg_to_rad(cub->player.left_angle.degree);
	cub->player.right_angle.degree += (cub->player.step.degree * cub->player.rot);
	cub->player.right_angle.radian = ft_deg_to_rad(cub->player.left_angle.degree);
}

/*
** Comms
*/

void ft_AR_cam_right(t_cub *cub)
{
	t_coor	coor_swap;
	double	rot_swap;

	coor_swap = cub->player.coor;
	rot_swap = cub->player.rot;
	ft_init_player(cub);
	cub->player.coor.x = coor_swap.x;
	cub->player.coor.y = coor_swap.y;
	cub->player.box.x = (int)floor(cub->player.coor.x);
	cub->player.box.y = (int)floor(cub->player.coor.y);
	cub->player.mid_x = (double)cub->player.plane.x / 2.0;
	cub->player.dist_to_plane = ft_dist_to_plane(cub);
	cub->player.rot = rot_swap + STEP_ROT;

	cub->player.left_angle.degree = (FOV / 2.0) + (cub->player.step.degree * cub->player.rot);
	cub->player.left_angle.radian = ft_deg_to_rad(cub->player.left_angle.degree);
}
