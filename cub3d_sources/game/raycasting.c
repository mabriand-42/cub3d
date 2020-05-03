# include "../../cub3d_header/cub3d.h"

int    ft_raycasting_no_g(t_cub *cub)
{
    ft_init_cast(cub);
    while (cub->cast.angle.degree >= cub->cast.step.degree)
    {   
        ft_affine_no_l(cub);
        //printf("a: %f\n", cub->cast.affine.a);
        //printf("b: %f\n", cub->cast.affine.b);
        ft_no_wall_l(cub);
        cub->cast.angle.degree -= (cub->cast.step.degree);
        cub->cast.angle.radian = ft_deg_to_rad(cub->cast.angle.degree);
        cub->cast.delta_screen = (cub->player.dist_to_plane)*sin(cub->cast.angle.radian)/cos(cub->cast.angle.radian);
        cub->cast.first_H = NO;
        cub->cast.first_V = NO;
    }
    ft_no_perp_wall(cub);
    /*ft_init_cast(cub);
    while (cub->cast.angle.degree >= cub->cast.step.degree)
    {   
        ft_affine_no_r(cub);
        printf("a: %f\n", cub->cast.affine.a);
        printf("b: %f\n", cub->cast.affine.b);
        ft_search_wall_no_r(cub);
        cub->cast.angle.degree -= (cub->cast.step.degree);
        cub->cast.angle.radian = ft_deg_to_rad(cub->cast.angle.degree);
        cub->cast.delta_screen = (cub->player.dist_to_plane)*sin(cub->cast.angle.radian)/cos(cub->cast.angle.radian);
        cub->cast.first_H = NO;
        cub->cast.first_V = NO;
    }*/
    return(1);
}