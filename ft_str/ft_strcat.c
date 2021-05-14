/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:26:08 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/14 19:42:07 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concatenate a string src into already allocated space dst
**
** Return NULL and leaves dst untouched if !src or !dst (unlike system strcpy)
*/

char	*ft_strcat(char *dst, const char *src)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (dst[i])
		i++;
	while (*src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dst);
}
