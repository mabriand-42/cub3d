# include "../../cub3d_header/cub3d.h"

//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur horizontal
int ft_h_bound_no_r(t_cub *cub)
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
    else
        cub->cast.ray_h.coor.y -= 1; //add ici et pas en bas 
    line_len = ft_strlen(cub->box_map[(int)cub->cast.ray_h.coor.y]);
    cub->cast.ray_h.coor.x = ((cub->cast.ray_h.coor.y)-b)/a;
    if(cub->cast.ray_h.coor.x >= (double)line_len) // peut _etre un pb ici return 0 ou 1 quand on sort de la map ?????
        return(1);
    cub->cast.ray_h.box.x = (int)floor(cub->cast.ray_h.coor.x);
    cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.y)-1;
    if(cub->box_map[cub->cast.ray_h.box.y][cub->cast.ray_h.box.x] == '1')
        return(1);
    return(0);
}

//renvoie 1 si ya un mur aux coornédonées sinon 0 pour mur vertical
int     ft_v_bound_no_r(t_cub *cub)
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
    else
        cub->cast.ray_v.coor.x += 1;
    cub->cast.ray_v.coor.y = (a*(cub->cast.ray_v.coor.x))+b;
    if(cub->cast.ray_v.coor.y < 0) //pas sur
        return(1);
    cub->cast.ray_v.box.y = (int)floor(cub->cast.ray_v.coor.y);
    cub->cast.ray_v.box.x = (int)(cub->cast.ray_v.coor.x);
     if(cub->box_map[cub->cast.ray_v.box.y][cub->cast.ray_v.box.x] == '1')
        return(1);
    return(0);
}

//cherche mur jusquà que l'angle vaut FOV/Resolution.x
void    ft_search_wall_no_r(t_cub *cub)
{
    while (cub->cast.ray_h.box.x >= 0 || cub->cast.ray_h.box.y >= 0 ||
           cub->cast.ray_v.box.x >= 0 || cub->cast.ray_v.box.y >= 0) //a verif sinon cub->player.box.x à la place de 0 pour inclure les conditions direct dans fctipns
    {
        if (ft_h_bound_no_r(cub) == 1 || ft_v_bound_no_r(cub) == 1) //pb car l'un avance plus vite que l'autre
        {
            if (ft_h_bound_no_r(cub) == 1)
                printf("HIT HORIZONTAL: (%d,%d)\n", cub->cast.ray_h.box.x, cub->cast.ray_h.box.y);
            else
                printf("HIT VERTICAL: (%d,%d)\n", cub->cast.ray_v.box.x, cub->cast.ray_v.box.y);
            return ;
        }
    }
    return ;
}