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
    a = (cub->player.dist_to_plane)/(cub->cast.delta_x);
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
    a = -(cub->player.dist_to_plane)/(cub->cast.delta_x);
    b = y-(a*x);
    cub->cast.affine.a = a;
    cub->cast.affine.b = b;
}