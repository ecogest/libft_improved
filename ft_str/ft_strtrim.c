/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:21:33 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/07 19:42:03 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*t;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, (s1[i - 1])))
		i--;
	if (!(t = (char *)malloc(sizeof(*t) * (i + 1))))
		return (NULL);
	t[i] = '\0';
	while (i--)
		t[i] = s1[i];
	return (t);
}
