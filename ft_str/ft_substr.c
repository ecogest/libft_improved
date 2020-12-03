/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:12:40 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/09 12:07:06 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int a, int b)
{
	return (a < b ? a : b);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	if (!(s))
		return (NULL);
	while (*s && start--)
		s++;
	substr = (char *)malloc(sizeof(*substr) * (ft_min(len, ft_strlen(s)) + 1));
	if (!(substr))
		return (NULL);
	i = 0;
	while (*s && len--)
		substr[i++] = *s++;
	substr[i] = '\0';
	return (substr);
}
