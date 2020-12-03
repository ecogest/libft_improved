/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:18:10 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/08 15:15:23 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	if (!(c))
		return (ft_strchr(s, '\0'));
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		s++;
	}
	return (last);
}
