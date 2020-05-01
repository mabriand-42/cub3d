#include "mlx.h"

/*int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	i;
	int	j;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xF800);
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
}*/


int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_loop(mlx_ptr);
	//return(0);
}