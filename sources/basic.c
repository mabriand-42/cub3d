/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:05:48 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/09 13:58:00 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*
** Saute tous les espaces dans une chaîne de
** caractères, à partir d'une position donnée.
** =========
** #1 : une chaîne de caractères.
** #2 : un pointeur sur une position.
** =========
*/ 

void	ft_skip_spaces(char *str, size_t *pos)
{
	while(str[*pos] == ' ')
		(*pos)++;
}

/*
** Cherche si le caractère c se trouve dans str.
** =========
** #1 : un caractère à chercher.
** #2 : une chaîne de caractères.
** =========
** Retourne 1 si le caractère a été trouvé, 
** 0 sinon.
*/ 

int		ft_find_char(char c, char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return(0);
}


/*
** Vérifie que c est un caractère autorisé pour
** la description de la map.
** =========
** #1 : un caractère.
** =========
** Retourne 1 si le caractère est valide, 0 sinon.
*/

int	ft_isvalidchar(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == ' ' || c == 'N' || c == 'S' 
	|| c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
** ft_strjoin(2) et retourne s2 si s1 est nulle,
** s1 si s2 est nulle, puis libère la chaîne de caractère s1.
** =========
*/ 

char			*ft_join_bis(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL && s2 != NULL)
		return (s2);
	else if (s1 != NULL && s2 == NULL)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
