/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:35:05 by mabriand          #+#    #+#             */
/*   Updated: 2020/03/02 19:40:10 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * remplit les n premiers octets de la zone mémoire pointée par s avec l'octet c.
**/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (len > 0)
	{
		while (i < len)
		{
			((unsigned char *)b)[i] = (unsigned char)c;
			i++;
		}
	}
	return (b);
}
