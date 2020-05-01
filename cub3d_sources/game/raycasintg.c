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
    cub->cast.angle = cub->player.angle;
    cub->cast.affine.a = 0;
    cub->cast.affine.b = 0;
    cub->cast.wall_hit = NO;
    cub->cast.ray = 0;
    cub->cast.first_H = NO;
    cub->cast.first_V = NO;
}

//cherche le coeff directeur et l'ordonnée à l'origine de la fonction rayon
void    ft_affine(t_cub *cub)
{
    double x;
    double y;
    double a;
    double b;

    x = cub->player.coor.x;
    y = cub->player.coor.y;
    printf("x dans ft_affine : %f\n", cub->player.coor.x);
	printf("y dans ft_affine : %f\n", cub->player.coor.y);
    a = (cub->player.dist_to_plane)/(cub->player.mid_x);
    b = y-(a*x);
    printf("a dans ft_affine : %f\n", a);
	printf("b dans ft_affine : %f\n", b);
    cub->cast.affine.a = a;
    cub->cast.affine.b = b;
}


//renvoie 1 si ya un mur aux coornédonées sinon 0
int    ft_h_bound(t_cub *cub)
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
    cub->cast.ray_h.box.x = (int)floor(cub->cast.ray_h.coor.x);
    cub->cast.ray_h.box.y = (int)(cub->cast.ray_h.coor.y) - 1;
    if(cub->box_map[cub->cast.ray_h.box.y][cub->cast.ray_h.box.x] == '1')
        return(1);
    cub->cast.ray_h.coor.y -= 1;
    return(0);
}


//renvoie 1 si ya un mur aux coornédonées sinon 0
int    ft_v_bound(t_cub *cub)
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
    cub->cast.ray_v.box.x = (int)(cub->cast.ray_v.coor.x)-1;
    cub->cast.ray_v.box.y = (int)floor(cub->cast.ray_v.coor.y);
    if(cub->box_map[cub->cast.ray_v.box.y][cub->cast.ray_v.box.x] == '1')
        return(1);
    cub->cast.ray_v.coor.x -= 1;
    return(0);
}

void    ft_search_for_wall(t_cub *cub)
{
    while (cub->cast.ray_h.box.x >= 0 || cub->cast.ray_h.box.y >=0 || cub->cast.ray_v.box.x >= 0 || cub->cast.ray_v.box.y >= 0)
    {
        if (ft_h_bound(cub) == 1 || ft_v_bound(cub) == 1)
        {
            printf("THAT IS A WALL\n");
            if (ft_h_bound(cub) == 1)
                printf("horizontal wall\n");
            else
                printf("vertical wall\n");
            printf("BOX H at x: %d, y: %d = %c\n", cub->cast.ray_h.box.x, cub->cast.ray_h.box.y, cub->box_map[cub->cast.ray_h.box.x][cub->cast.ray_h.box.y]);
            printf("BOX V at x: %d, y: %d = %c\n", cub->cast.ray_v.box.x, cub->cast.ray_v.box.y, cub->box_map[cub->cast.ray_v.box.x][cub->cast.ray_v.box.y]);
            return ;
        }
        else
        {
            printf("NO\n");
        }
    }
    return ;
}

int    ft_raycasting(t_cub *cub)
{
    ft_init_cast(cub);
    ft_affine(cub);
    ft_search_for_wall(cub);

    return(1);
}