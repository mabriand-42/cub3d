#include "../../cub3d_header/cub3d.h"

void	ft_init_draw(t_cub *cub)
{
	cub->draw.ceiling.x = -1;
	cub->draw.ceiling.y = -1; 
	cub->draw.floor.x = -1; 
	cub->draw.floor.y = -1;
	cub->draw.wall.x = -1;
	cub->draw.wall.y = -1;
}

int		ft_scale(double	d_to_plane, double d_to_wall)
{
	double	d_wall;
	int		i_wall;

	d_wall = d_to_plane / d_to_wall;
	i_wall = (int)round(d_wall);
	return (i_wall);
}

void	ft_draw(t_cub *cub, double d_to_wall)
{
	int		slice;
	slice = ft_scale(cub->player.dist_to_plane, d_to_wall);
	cub->draw.ceiling.x = 0;
	cub->draw.ceiling.y = ((cub->player.plane.y) / 2) - (slice / 2) - 1; 
	cub->draw.floor.x = ((cub->player.plane.y) / 2) + (slice / 2); 
	cub->draw.floor.y = cub->player.plane.y - 1;
	cub->draw.wall.x = cub->draw.ceiling.y + 1;
	cub->draw.wall.y = cub->draw.floor.x - 1;
}

void	ft_draw_pxl_line(t_cub *cub, double d_to_wall, int i)
{
	ft_init_draw(cub);
	ft_draw(cub, d_to_wall);
	while (cub->draw.j <= cub->draw.ceiling.y)
	{	
		mlx_pixel_put(cub->mlx_ptr, cub->win.win_ptr, cub->draw.i, cub->draw.j, 0xB986);
		cub->draw.j++;
	}
	while(cub->draw.j <= cub->draw.wall.y)
	{	
		mlx_pixel_put(cub->mlx_ptr, cub->win.win_ptr, cub->draw.i, cub->draw.j, 0xF900);
		cub->draw.j++;
	}
	while(cub->draw.j <= cub->draw.floor.y)
	{	
		mlx_pixel_put(cub->mlx_ptr, cub->win.win_ptr, cub->draw.i, cub->draw.j, 0xD120);
		cub->draw.j++;
	}
}