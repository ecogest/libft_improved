/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:44:46 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/06 20:30:02 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Search haystack for a needle. Return matching haystack pointer.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	while (needle[i] && haystack[i] == needle[i])
		i++;
	if (!needle[i])
		return ((char *)haystack);
	else if (*haystack)
		return (ft_strstr(haystack + 1, needle));
	else
		return (NULL);
}
