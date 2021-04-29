/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:50:54 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 19:53:40 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Pour protéger strlcpy :
** 	if (src == NULL || dest == NULL)
** 		return (0);
** Mais ne reproduit pas le strlcpy standard.
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i + 2 <= size)
		dest[i++] = *src++;
	if (size)
		dest[i] = '\0';
	while (*src++)
		i++;
	return (i);
}
