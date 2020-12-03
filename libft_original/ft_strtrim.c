/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:21:33 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/09 12:10:19 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const c, char const *set)
{
	while (*set && c != *set)
		set++;
	return (*set ? 1 : 0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*t;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_is_set(*s1, set))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_is_set(s1[i - 1], set))
		i--;
	if (!(t = (char *)malloc(sizeof(*t) * (i + 1))))
		return (NULL);
	t[i] = '\0';
	while (i--)
		t[i] = s1[i];
	return (t);
}
