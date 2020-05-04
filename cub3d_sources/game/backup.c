# include "../../cub3d_header/cub3d.h"

//cherche mur jusquà que l'angle vaut FOV/Resolution.x
double  ft_no_wall_left_new(t_cub *cub)
{
    double  dist_h;
    double  dist_v;
    int     h_bound;
    int     v_bound;

    dist_h = 0;
    dist_v = 0;
    h_bound = 0;
    v_bound = 0;

    while (h_bound == 0)
            h_bound = ft_no_horizontal_l(cub);
    while (v_bound == 0)
            v_bound = ft_no_vertical_l(cub);
    dist_h = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor);
    dist_v = ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor);
    if (dist_h <= dist_v)
    {
        printf("\nLH shorter coor (%f,%f)\n", cub->cast.ray_h.coor.x, cub->cast.ray_h.coor.y);
        printf("LEFT hit H at (%d,%d)\n", cub->cast.ray_h.box.x, cub->cast.ray_h.box.y);
        return(dist_h);
    } 
    printf("\nLV shorter coor (%f,%f)\n", cub->cast.ray_v.coor.x, cub->cast.ray_v.coor.y);
    printf("LEFT hit V at (%d,%d)\n", cub->cast.ray_v.box.x, cub->cast.ray_v.box.y);
    return(dist_v);      
}


/*double  ft_no_wall_left_new2(t_cub *cub)
{
    double  dist_h;
    double  dist_v;
    int     h_bound;
    int     v_bound;

    dist_h = 0;
    dist_v = 0;
    h_bound = 0;
    v_bound = 0;

    while (h_bound == 0 && v_bound == 0)
    {   
        h_bound = ft_no_horizontal_r(cub);
        v_bound = ft_no_vertical_r(cub);
    }
    if (h_bound == 1 && v_bound == 0)
    {
        printf("h ok\n");
        while (v_bound == 0)
            v_bound = ft_no_vertical_l(cub);
    }
    else if (h_bound == 0 && v_bound == 1)
    {
        printf("v ok\n");
        while (h_bound == 0)
            h_bound = ft_no_horizontal_l(cub);
    }
    if (h_bound == 1 && v_bound == 1)
    {
        printf("both ok\n");
        dist_h = ft_hypotenuse(cub->player.coor, cub->cast.ray_h.coor);
        dist_v = ft_hypotenuse(cub->player.coor, cub->cast.ray_v.coor);
        if (dist_h <= dist_v)
        {
            printf("\nLH shorter coor (%f,%f)\n", cub->cast.ray_h.coor.x, cub->cast.ray_h.coor.y);
            printf("LEFT hit H at (%d,%d)\n", cub->cast.ray_h.box.x, cub->cast.ray_h.box.y);
            return(dist_h);
        } 
        printf("\nLV shorter coor (%f,%f)\n", cub->cast.ray_v.coor.x, cub->cast.ray_v.coor.y);
        printf("LEFT hit V at (%d,%d)\n", cub->cast.ray_v.box.x, cub->cast.ray_v.box.y);
        return(dist_v);
    }
    return(0);    
}*/