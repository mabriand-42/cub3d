# include "../../cub3d_header/cub3d.h"

void    ft_init_cast(t_cub *cub)
{
    cub->cast.ray_h.box.x = 0;
    cub->cast.ray_h.box.y = 0;
    cub->cast.ray_h.coor.x = 0;
    cub->cast.ray_h.coor.y = 0;
    cub->cast.ray_v.box.x = 0;
    cub->cast.ray_v.box.y = 0;
    cub->cast.ray_v.coor.x = 0;
    cub->cast.ray_v.coor.y = 0;
    cub->cast.angle = cub->player.fov;
    cub->cast.step = cub->player.step;
    cub->cast.delta_x = cub->player.mid_x;
    cub->cast.affine.a = 0;
    cub->cast.affine.b = 0;
    cub->cast.wall_hit = NO;
    cub->cast.ray = 0;
    cub->cast.first_H = NO;
    cub->cast.first_V = NO;
}

//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur perependicular horizontal
int    ft_cp_bound_no_l(t_cub *cub)
{
    if (cub->cast.first_H == NO)
    {
        cub->cast.ray_h.coor.x = (cub->player.coor.x)-0.5;
        cub->cast.ray_h.coor.y = (cub->player.coor.y)-0.5;
        cub->cast.first_H = YES;
    }
    cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.y)-1;
    if(cub->box_map[cub->cast.ray_h.box.y][cub->cast.ray_h.box.x] == '1')
        return(1);
    cub->cast.ray_h.coor.y -= 1;
    return(0);
}

//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur horizontal
int    ft_h_bound_no_l(t_cub *cub)
{
    double  a;
    double  b;

    a = cub->cast.affine.a;
    b = cub->cast.affine.b;
    if (cub->cast.first_H == NO)
    {
        cub->cast.ray_h.coor.y = (cub->player.coor.y)-0.5;
        cub->cast.first_H = YES;
    }
    cub->cast.ray_h.coor.x = ((cub->cast.ray_h.coor.y)-b)/a;
    if(cub->cast.ray_h.coor.x < 0)
        return(1);
    cub->cast.ray_h.box.x = (int)floor(cub->cast.ray_h.coor.x);
    cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.y)-1;
    if(cub->box_map[cub->cast.ray_h.box.y][cub->cast.ray_h.box.x] == '1')
        return(1);
    cub->cast.ray_h.coor.y -= 1;
    return(0);
}


//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur vertical
int    ft_v_bound_no_l(t_cub *cub)
{
    double  a;
    double  b;

    a = cub->cast.affine.a;
    b = cub->cast.affine.b;
    if (cub->cast.first_V == NO)
    {
        cub->cast.ray_v.coor.x = (cub->player.coor.x)-0.5;
        cub->cast.first_V = YES;
    }
    cub->cast.ray_v.coor.y = (a*(cub->cast.ray_v.coor.x))+b;
    if(cub->cast.ray_v.coor.y < 0)
        return(1);
    cub->cast.ray_v.box.y = (int)floor(cub->cast.ray_v.coor.y);
    cub->cast.ray_v.box.x = (int)(cub->cast.ray_v.coor.x)-1;
    if(cub->box_map[cub->cast.ray_v.box.y][cub->cast.ray_v.box.x] == '1')
        return(1);
    cub->cast.ray_v.coor.x -= 1;
    return(0);
}

//cherche mur jusquà que l'angle vaut FOV/Resolution.x
void    ft_search_wall_no_l(t_cub *cub)
{
    while (cub->cast.ray_h.box.x >= 0 || cub->cast.ray_h.box.y >= 0 ||
           cub->cast.ray_v.box.x >= 0 || cub->cast.ray_v.box.y >= 0)
    {
        if (ft_h_bound_no_l(cub) == 1 || ft_v_bound_no_l(cub) == 1)
        {
            if (ft_h_bound_no_l(cub) == 1)
                printf("H hit: (%d,%d)\n", cub->cast.ray_h.box.x, cub->cast.ray_h.box.y);
            else
                printf("V hit: (%d,%d)\n", cub->cast.ray_v.box.x, cub->cast.ray_v.box.y);
            return ;
        }
    }
    return ;
}

//cherche mur perpendiculaire
void    ft_perpendicular_wall_no_l(t_cub *cub)
{
    while (cub->cast.ray_h.box.y >= 0)
    {
        if (ft_cp_bound_no_l(cub) == 1)
        {
            printf("Perpendicular hit: (%d,%d)\n", cub->cast.ray_h.box.x, cub->cast.ray_h.box.y);
            return;
        }
    }
    return ;
}
