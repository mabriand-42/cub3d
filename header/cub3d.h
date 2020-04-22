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

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../libft/libft_header/libft.h"

/*
**VARIABLE
*/

/*
**STRUCTURE
*/

typedef	struct	s_resolution
{
	size_t x;
	size_t y;
}				t_resolution;

typedef struct	s_textures
{
	char *path_NO;
	char *path_SO;
	char *path_WE;
	char *path_EA;
	char *path_S;
}				t_textures;

typedef	struct	s_color
{
	int R;
	int G;
	int B;
}				t_color;

typedef enum	s_bool
{
	Empty,
	Filled,
}				t_bool;

typedef struct	s_check
{
	t_bool	Resolution;
	t_bool	NO_texture;
	t_bool	SO_texture;
	t_bool	WE_texture;
	t_bool	EA_texture;
	t_bool	S_texture;
	t_bool	Ground_color;
	t_bool	Ceiling_color;
}				t_check;

typedef struct	s_config
{
	t_resolution	R;
	t_color			F;
	t_color			C;
	t_textures		T;
	t_check			check;
}				t_config;

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
	t_cardinal	player;
}				t_map;

/*
**PROTOTYPE
*/

/*
** Gnl
*/

int				gnl(int fd, char **line);

/*
** Basic
*/

void			ft_skip_spaces(char *str, size_t *pos);
int				ft_find_char(char c, char *str);
int				ft_isvalidchar(char c);
char			*ft_join_bis(char *s1, char *s2);
char			*ft_str_null_bis(char *s1, char *s2);

/*
** Config
*/

int				ft_check_id(char c1, char c2);
int				ft_find_id(char *line, char *id, size_t *pos);
int				ft_id_s(size_t *pos, char *line, char *id);
int				ft_id_rfc(size_t *pos, char *line, char *id);
int				ft_id_nwe(size_t *pos, char *line, char *id);
int				ft_check_config(t_check check);
void			ft_update_player(char c, t_map *m);

/*
** Init
*/

void			ft_init_config(t_config *config);
void			ft_init_check(t_check *check);
void			ft_init_map(t_map *map);

/*
** Resolution
*/

size_t			ft_axis(char *line, size_t *pos);
int				ft_r(char *line, size_t *pos, t_resolution *resolution, t_bool *check);
int				ft_xy(char *line, size_t *pos, t_resolution *R);

/*
** Color
*/

int				ft_color(char *line, size_t *pos);
int				ft_rgb(char *line, size_t *pos, t_color *C);
int				ft_cf(char *line, size_t *pos, t_color *color, t_bool *check);

/*
** Texture
*/

int				ft_path(char *line, size_t *pos, char **path);
int				ft_t(char *line, size_t *pos, char **path, t_bool *check);

/*
** Map
*/

int				ft_closed_map(char *line, size_t *pos);
int				ft_cmp_char(char c1, char c2, t_map *map);
int				ft_cmp_prev_next(char c1, char *line, size_t index);
int				ft_duo_line(char *prev, char *next, t_map *map);
int				ft_duo_line_bis(char *prev, char *next, size_t *ptr_i, size_t *ptr_j);

void			ft_join_for_map(t_map *map, char *next, int *ret);
int				ft_lines(char *line, char *next, t_map *map, t_config *config);
void			ft_transform_map(t_map *map);

/*
** Parsing
*/

int				ft_elem_parsing(char *line, t_config *config);
int				ft_orient_gnl(int ret_gnl, t_map *map, t_config *config, char *line, char *next);
int				ft_get_config(char *id, char *line, size_t *pos, t_config *c);

#endif