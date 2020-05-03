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
    cub->cast.delta_screen = cub->player.mid_x;
    cub->cast.affine.a = 0;
    cub->cast.affine.b = 0;
    cub->cast.wall_hit = NO;
    cub->cast.ray = 0;
    cub->cast.first_H = NO;
    cub->cast.first_V = NO;
}

//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur perependicular horizontal
int    ft_no_cp_bound(t_cub *cub)
{
    if (cub->cast.first_H == NO)
    {
        cub->cast.ray_h.coor.x = (cub->player.coor.x)-0.5;
        cub->cast.ray_h.coor.y = (cub->player.coor.y)-0.5;
        cub->cast.first_H = YES;
    }
    if (cub->cast.ray_h.coor.y < 1 || cub->cast.ray_h.coor.x < 0)
        return (0);
    cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.x);
    cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.y)-1;
    if(cub->box_map[cub->cast.ray_h.box.y][cub->cast.ray_h.box.x] == '1')
        return(1);
    cub->cast.ray_h.coor.y -= 1;
    return(0);
}

//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur horizontal
int    ft_no_horizontal_l(t_cub *cub)
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
    if (cub->cast.ray_h.coor.x < 0 || cub->cast.ray_h.coor.y < 1)
        return (0);
    //printf("ft_h coor (%f,%f)\n", cub->cast.ray_h.coor.x, cub->cast.ray_h.coor.y);
    cub->cast.ray_h.box.x = (int)floor(cub->cast.ray_h.coor.x);
    cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.y)-1;
    if(cub->box_map[cub->cast.ray_h.box.y][cub->cast.ray_h.box.x] == '1')
        return(1);
    cub->cast.ray_h.coor.y -= 1;
    return(0);
}


//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur vertical
int    ft_no_vertical_l(t_cub *cub)
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
    if (cub->cast.ray_v.coor.x < 1 || cub->cast.ray_v.coor.y < 0)
        return (0);
    //printf("ft_v coor (%f,%f)\n", cub->cast.ray_v.coor.x, cub->cast.ray_v.coor.y);    
    cub->cast.ray_v.box.x = (int)(cub->cast.ray_v.coor.x)-1;
    cub->cast.ray_v.box.y = (int)floor(cub->cast.ray_v.coor.y);
    if(cub->box_map[cub->cast.ray_v.box.y][cub->cast.ray_v.box.x] == '1')
        return(1);
    cub->cast.ray_v.coor.x -= 1;
    return(0);
}

//cherche mur jusquà que l'angle vaut FOV/Resolution.x
double    ft_no_wall_l(t_cub *cub)
{
    double  dist_h;
    double  dist_v;
    int     h_bound;
    int     v_bound;

    dist_h = 0;
    dist_v = 0;
    h_bound = 0;
    v_bound = 0;
    //while ()
    while (/*cub->cast.ray_h.box.x >= 0 || cub->cast.ray_h.box.y >= 0 ||
           cub->cast.ray_v.box.x >= 0 || cub->cast.ray_v.box.y >= 0*/h_bound == 0 && v_bound == 0)
    {
        h_bound = ft_no_horizontal_l(cub);
        v_bound = ft_no_vertical_l(cub);
        //printf("LEFT bound H: %d, V: %d)\n", h_bound, v_bound);
        if (h_bound == 1 && v_bound == 0)
        {
            printf("LEFT hit H at (%d,%d)\n", cub->cast.ray_h.box.x, cub->cast.ray_h.box.y);
            printf("coor (%f,%f)\n", cub->cast.ray_h.coor.x, cub->cast.ray_h.coor.y);
            return(ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor));
        }
        else if (h_bound == 0 && v_bound == 1)
        {
            printf("LEFT hit V at (%d,%d)\n", cub->cast.ray_v.box.x, cub->cast.ray_v.box.y);
            printf("coor (%f,%f)\n", cub->cast.ray_v.coor.x, cub->cast.ray_v.coor.y);
            return(ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor));
        }
        else if (h_bound == 1 && v_bound == 1)
        {
            dist_h = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor);
            dist_v = ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor);
            if (dist_h <= dist_v)
            {
                printf("\n\nLH shorter coor (%f,%f)\n\n", cub->cast.ray_h.coor.x, cub->cast.ray_h.coor.y);
                return(dist_h);
            } 
            printf("\n\nLV shorter coor (%f,%f)\n\n", cub->cast.ray_v.coor.x, cub->cast.ray_v.coor.y);
            return(dist_v);
        }
        else
        {
            //printf("keep going...");
        }
    }
    return(0);
}

//cherche mur perpendiculaire
double    ft_no_perp_wall(t_cub *cub)
{
    double  dist_h;
    int     h_bound;

    dist_h = 0;
    h_bound = 0;
    while (h_bound == 0)
    {
        h_bound = ft_no_horizontal_l(cub);
        if (h_bound == 1)
            return(ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor));
    }
    return(0);
}
