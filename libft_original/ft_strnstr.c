/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:07:31 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/04 15:02:09 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && len--)
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[i] && i <= len)
			i++;
		if (!(needle[i]))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
