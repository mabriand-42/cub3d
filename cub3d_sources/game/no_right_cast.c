# include "../../cub3d_header/cub3d.h"

//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur horizontal
int ft_no_horizontal_r(t_cub *cub)
{
    double  a;
    double  b;
    size_t  line_len;

    a = cub->cast.affine.a;
    b = cub->cast.affine.b;
    if (cub->cast.first_H == NO)
    {
        cub->cast.ray_h.coor.y = (cub->player.coor.y)-0.5;
        cub->cast.first_H = YES;
    }
    line_len = ft_strlen(cub->box_map[(int)cub->cast.ray_h.coor.y]);
    cub->cast.ray_h.coor.x = ((cub->cast.ray_h.coor.y)-b)/a;
    if(cub->cast.ray_h.coor.x >= (double)line_len || cub->cast.ray_h.coor.y < 1)
        return(0);
    cub->cast.ray_h.box.x = (int)floor(cub->cast.ray_h.coor.x);
    cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.y)-1;
    if(cub->box_map[cub->cast.ray_h.box.y][cub->cast.ray_h.box.x] == '1')
        return(1);
    cub->cast.ray_h.coor.y -= 1;
    return(0);
}

//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur vertical
int     ft_no_vertical_r(t_cub *cub)
{
    double  a;
    double  b;
    size_t  line_len;

    a = cub->cast.affine.a;
    b = cub->cast.affine.b;
    if (cub->cast.first_V == NO)
    {
        cub->cast.ray_v.coor.x = (cub->player.coor.x)+0.5;
        cub->cast.first_V = YES;
    }
    cub->cast.ray_v.coor.y = (a*(cub->cast.ray_v.coor.x))+b;

    if(cub->cast.ray_h.coor.x >= (double)(line_len) || cub->cast.ray_v.coor.y < 0) //pas sur
        return(0);
    cub->cast.ray_v.box.x = (int)(cub->cast.ray_v.coor.x);
    cub->cast.ray_v.box.y = (int)floor(cub->cast.ray_v.coor.y);
    if(cub->box_map[cub->cast.ray_v.box.y][cub->cast.ray_v.box.x] == '1')
        return(1);
    cub->cast.ray_v.coor.x += 1;
    return(0);
}

//cherche mur jusquà que l'angle vaut FOV/Resolution.x
double    ft_no_wall_r(t_cub *cub)
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
        h_bound = ft_no_horizontal_r(cub);
        v_bound = ft_no_vertical_r(cub);
        //printf("RIGHT bound H: %d, V: %d)\n", h_bound, v_bound);
        if (h_bound == 1 && v_bound == 0)
        {
            printf("RIGHT hit H at (%d,%d)\n", cub->cast.ray_h.box.x, cub->cast.ray_h.box.y);
            printf("coor (%f,%f)\n", cub->cast.ray_h.coor.x, cub->cast.ray_h.coor.y);
            return(ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor));
        }
        else if (h_bound == 0 && v_bound == 1)
        {
            printf("RIGHT hit V at (%d,%d)\n", cub->cast.ray_v.box.x, cub->cast.ray_v.box.y);
            printf("coor (%f,%f)\n", cub->cast.ray_v.coor.x, cub->cast.ray_v.coor.y);
            return(ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor));
        }
        else if (h_bound == 1 && v_bound == 1)
        {
            dist_h = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor);
            dist_v = ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor);
            if (dist_h <= dist_v)
            {
                printf("\n\nRH shorter coor (%f,%f)\n\n", cub->cast.ray_h.coor.x, cub->cast.ray_h.coor.y);
                return(dist_h);
            } 
            printf("\n\nRV shorter coor (%f,%f)\n\n", cub->cast.ray_v.coor.x, cub->cast.ray_v.coor.y);
            return(dist_v);
        }
        else
        {
            //printf("keep going...");
        }
    }
    return(0);
}
