/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:50:28 by mabriand          #+#    #+#             */
/*   Updated: 2019/11/28 11:52:02 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Examine les n premiers octets de la zone mémoire pointée par s
 * à la recherche du caractère c. Le premier octet correspondant à c
 * (interprété comme un unsigned char) arrête l'opération.
**/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		c2;
	unsigned char		*str;

	i = 0;
	c2 = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == c2)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
