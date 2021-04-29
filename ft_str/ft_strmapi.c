/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:38:25 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 20:09:49 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*t;
	int		i;

	if (!s)
		return (NULL);
	t = (char *)malloc(sizeof(*t) * (ft_strlen(s) + 1));
	if (!t)
		return (NULL);
	i = 0;
	while (*s)
	{
		t[i] = f((unsigned int)i, *s++);
		i++;
	}
	t[i] = '\0';
	return (t);
}
