/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:27:37 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/10 15:09:18 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Alloue (avec malloc(3)) et retourne une chaine de caractères
 * issue de la chaine ’s’.
 * Cette nouvelle chaine commence à l’index ’start’ et
 * a pour taille maximale ’len’
**/

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * Alloue (avec malloc(3)) et retourne un tableau
 * de chaines de caracteres obtenu en séparant ’s’ à
 * l’aide du caractère ’c’, utilisé comme délimiteur.
 * Le tableau doit être terminé par NULL.
**/

int		ft_countword(char *s, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

void		ft_free_split(char **tab, size_t index)
{
	size_t i;

	i = 0;
	if (index > 0)
		index--;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

char		**ft_createsplit(char *s, char c, char **newtab)
{
	size_t	i;
	size_t	start;
	size_t	index;

	i = 0;
	index = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			start = 0;
			while (s[i + start] != c && s[i + start] != '\0')
				start++;
			newtab[++index] = ft_substr(s, i, start);
			if (newtab[index] == NULL)
			{
				ft_free_split(newtab, index);
				break ;
			}
			i = i + start;
		}
	}
	return (newtab);
}

char			**ft_split(char *s, char c)
{
	char		**tab;
	size_t		len;

	tab = NULL;
	if (s != NULL)
	{
		len = ft_countword(s, c);
		tab = (char **)malloc(sizeof(*tab) * (len + 1));
		if (tab != NULL)
		{
			tab[len] = NULL;
			tab = ft_createsplit(s, c, tab);
		}
	}
	return (tab);
}

void			ft_transform_map(t_map *map)
{
	t_map m;

	m = *map;
	m.two_d = ft_split(m.map, '-');
	*map = m;
}