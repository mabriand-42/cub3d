/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriand <mabriand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:15:25 by mabriand          #+#    #+#             */
/*   Updated: 2020/01/16 14:15:41 by mabriand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

/**
 * Écrit la chaine de caractères ’s’ sur le file
 * descriptor donné.
**/
void	ft_putstr(char *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
}