/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:50:40 by mabriand          #+#    #+#             */
/*   Updated: 2019/11/28 11:59:13 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
**/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len;
	size_t lensrc;
	size_t lendest;
	size_t j;

	lensrc = ft_strlen(src);
	lendest = ft_strlen(dst);
	j = 0;
	if (dstsize <= lendest)
		len = lensrc + dstsize;
	else
		len = lensrc + lendest;
	if (dstsize > lendest)
	{
		while (src[j] != '\0' && lendest < dstsize - 1)
		{
			dst[lendest] = src[j];
			lendest++;
			j++;
		}
		dst[lendest] = '\0';
	}
	return (len);
}
