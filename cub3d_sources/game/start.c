
#include "../../cub3d_header/cub3d.h"

/*
** Coms
*/
int     ft_start(t_cub  *cub)
{

    cub->done = YES;
    if((cub->mlx_ptr = mlx_init()) == NULL)
    {
        printf("ERROR : seems like the connection couldn't be made!\n\n");
        return (0);
    }


    /*if (cub->save == NO)
    {
        if ((cub->win.win_ptr = mlx_new_window(cub->mlx_ptr, cub->win.R.x, cub->win.R.y, "test")) == NULL)
        {
            printf("ERROR : seems like window creation failed!\n\n");
            return (0);
        }
        if(ft_get_img(cub) == 0)
        {
            printf("ERROR : seems like getting images failed!\n\n");
            return (0);
        }   
        ft_init_img(cub);
        

        mlx_loop(cub->mlx_ptr);
        return(1);
    }
    if (cub->save == YES)
    {
        cub->win.win_ptr = NULL; // PK ??
        ft_get_img(&cub);
        ft_init_img(&cub);
        
    }*/

    if ((cub->win.win_ptr = mlx_new_window(cub->mlx_ptr, cub->win.R.x, cub->win.R.y, "test")) == NULL)
    {
        printf("ERROR : seems like window creation failed!\n\n");
        return (0);
    }

	ft_raycasting(cub);


    printf("YEAH !\n");
    mlx_loop(cub->mlx_ptr);
    return(1);
    
}


