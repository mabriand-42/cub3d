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

typedef struct	s_configuration
{
	t_resolution	R;
	t_color			F;
	t_color			C;
	t_textures		T;

	t_check			check;
}				t_configuration;

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
** Get-next-line
*/

int				get_next_line(int fd, char **line);
ssize_t			ft_search_line(char *s);
char			*ft_strndup(char *s1, size_t size);
void			ft_reinit_buffer(ssize_t start, char *buffer);
char			*ft_create_line(char *str, char **line);

size_t			ft_strlen(char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_join_bis(char *s1, char *s2);

/*
** Libft
*/

int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_islinebreak(int c);
void			ft_skip_spaces(char *str, size_t *pos);
int				ft_is_in_string(char c, char *str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_strcmp(const char *s1, const char *s2);

char			*ft_substr(char *s, unsigned int start, size_t len);
int				ft_countword(char *s, char c);
void			ft_free_split(char **tab, size_t index);
char			**ft_createsplit(char *s, char c, char **newtab);
char			**ft_split(char *s, char c);
void			ft_transform_map(t_map *map);



/*
**
*/

int				ft_is_identifier(char *line, char *identifier, size_t *pos);
int				ft_check_identifier(char c1, char c2);

void			ft_init_config(t_configuration *config);
void			ft_init_check(t_check *check);
void			ft_init_map(t_map *map);
int				ft_is_config_full(t_check check);

int				ft_elem_parsing(char *line, t_configuration *config);

/*
** Resolution
*/

int				ft_r(char *line, size_t *pos, t_resolution *resolution, t_bool *check);
int				ft_resolution(char *line, size_t *pos, t_resolution *R);
size_t			ft_get_r_info(char *line, size_t *pos);

/*
** Color
*/

int				ft_cf(char *line, size_t *pos, t_color *color, t_bool *check);
int				ft_color(char *line, size_t *pos, t_color *C);
int				ft_get_cf_info(char *line, size_t *pos);

/*
** Path
*/

int				ft_path(char *line, size_t *pos, char **path);
int				ft_get_t_info(char *line, size_t *pos, char **path, t_bool *check);

/*
** Map
*/

int				ft_isvalidchar(char c);
int				ft_cmp_char(char c1, char c2, t_map *map);
int				ft_cmp_prev_next(char c1, char *line, size_t index);
int				ft_check_rest_line(char *line, size_t *pos);
int				ft_duo_line(char *prev, char *next, t_map *map);
int				ft_check_isolated_line(char *line);
int				ft_check_last_line(char *line);

void			ft_join_for_map(t_map *map, char *next, int *ret);
int				ft_lines(char *line, char *next, t_map *map, t_configuration *config);
int				ft_orient_gnl(int ret_gnl, t_map *map, t_configuration *config, char *line, char *next);

#endif