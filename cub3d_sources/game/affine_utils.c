# include "../../cub3d_header/cub3d.h"

//cherche le coeff directeur et l'ordonnée à l'origine de la fonction rayon
void    ft_affine_no_l(t_cub *cub)
{
    double x;
    double y;
    double a;
    double b;

    x = cub->player.coor.x;
    y = cub->player.coor.y;
    a = (cub->player.dist_to_plane)/(cub->cast.delta_screen);
    b = y-(a*x);
    cub->cast.affine.a = a;
    cub->cast.affine.b = b;
}

void    ft_affine_no_r(t_cub *cub)
{
    double x;
    double y;
    double a;
    double b;

    x = cub->player.coor.x;
    y = cub->player.coor.y;
    a = -(cub->player.dist_to_plane)/(cub->cast.delta_screen);
    b = y-(a*x);
    cub->cast.affine.a = a;
    cub->cast.affine.b = b;
}

double    ft_hypotenuse(t_coor  start, t_coor new)
{
    double  delta_x;
    double  delta_y;
    double  dist_to_wall;

    delta_x = fabs(start.x-new.x);
    delta_y = fabs(start.y-new.y);
    dist_to_wall = sqrt((delta_x*delta_x)+(delta_y*delta_y));
    return(dist_to_wall);
}