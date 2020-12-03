/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:43:47 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/04 16:52:25 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	if (!(dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		dest[i++] = *s1++;
	dest[i] = '\0';
	return (dest);
}