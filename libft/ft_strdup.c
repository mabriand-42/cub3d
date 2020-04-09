/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:57:14 by mabriand          #+#    #+#             */
/*   Updated: 2019/12/05 12:21:06 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Renvoie un pointeur sur la chaîne dupliquée depuis s,
 * ou NULL s'il n'y avait pas assez de mémoire.
**/

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s;
	size_t	size;
	char	*copy;

	i = 0;
	s = (char *)s1;
	size = ft_strlen(s);
	copy = ((char *)malloc(sizeof(*copy) * (size + 1)));
	if (copy == NULL)
		return (NULL);
	while (i < size)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
