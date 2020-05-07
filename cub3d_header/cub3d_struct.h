/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:01:14 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/12 13:20:22 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

/*
**-------------------------------------------------------------------VARIABLE---
*/

/*
** -----------------------------------------------------------------STRUCTURE---
*/

typedef	struct	s_resolution
{
	int x;
	int y;
}				t_resolution;

typedef struct	s_texture
{
	char *path_NO;
	char *path_SO;
	char *path_WE;
	char *path_EA;
	char *path_S;
}				t_texture;

typedef	struct	s_color
{
	int R;
	int G;
	int B;
}				t_color;
typedef enum	s_bool
{
	NO,
	YES,
}				t_bool;

typedef struct	s_check
{
	t_bool	Resolution;
	t_bool	NO_texture;
	t_bool	SO_texture;
	t_bool	WE_texture;
	t_bool	EA_texture;
	t_bool	S_texture;
	t_bool	Floor_color;
	t_bool	Ceiling_color;
}				t_check;

typedef struct	s_config
{
	t_resolution	R;
	t_color			F;
	t_color			C;
	t_texture		T;
	t_check			check;
}				t_config;

typedef	struct	s_duo
{
	char	*line;
	char	*prev;
}				t_duo;

typedef enum	s_cardinal
{
	Not_given,
	North,
	South,
	East,
	West,
}				t_cardinal;

typedef struct	s_map
{
	char		*map;
	char 		**two_d;
	t_bool		first;
	t_cardinal	cardinal;
}				t_map;



//////////////////////////////////////////////////////
typedef struct  s_pars_data
{
    t_config    config;
    t_map       map;
	t_bool		save;
}               t_pars_data;
//////////////////////////////////////////////////////


typedef	struct	s_window
{
	void			*win_ptr;
	t_resolution	R; // même que la R de img, et plane

}				t_window;

typedef	struct	s_image
{
	void			*img_ptr;
	char 			*addr;
	int				bpp;
	int				size_line;
	int				endian;
	t_resolution	R; // même que la R de win, et plane
}				t_image;


typedef	struct	s_text_img
{
	t_image		NO_t;
	t_image		SO_t;
	t_image		WE_t;
	t_image		EA_t;
	t_image		S_t;
	t_texture	path;
}				t_text_img;

typedef struct	s_box
{
	int	x; 
	int	y;
}				t_box;

typedef struct	s_coor
{
	double	x;
	double	y;
}				t_coor;

typedef struct	s_pos
{
	t_box	box;
	t_coor	coor;
}				t_pos;


typedef	struct	s_vector
{
	int	vect_x;
	int	vect_y;
}				t_vector;

typedef struct	s_angle
{
	double	degree;
	double	radian;
}				t_angle;

typedef struct	s_player
{
	t_box			box; //yen a qu'une a un instant t	
	t_coor			coor; //
	t_vector		dir;//
	t_resolution	plane;
	double			mid_x;
	double			mid_y;
	double			dist_to_plane;
	t_angle			fov;
	t_angle			step;
}				t_player;

typedef	struct	s_affine
{
	double	a;
	double	b;
}				t_affine;

typedef	struct	s_cast
{
	t_pos		ray_h;
	t_pos		ray_v;
	t_angle		angle;
	t_angle		step;
	double		delta_screen;
	t_affine	affine;
	t_bool		wall_hit;
	//int			ray;
	t_bool		first_H;
	t_bool		first_V;
	t_cardinal	wall; //

}				t_cast;

typedef struct	s_draw
{
	t_color	C;
	t_color	F;
	int		C_rgb;
	int		F_rgb;
	t_box	ceiling;
	t_box	wall;
	t_box	floor;
	int		i;
	int		j;
}				t_draw;

typedef	struct	s_cub 
{	
	void		*mlx_ptr;
	t_bool		done;
	t_bool		save;


	t_window	win;
	t_image		img;

	t_text_img	text;

	char		**box_map;

	t_player	player;
	t_cast		cast;
	t_draw		draw;
}				t_cub;





#endif