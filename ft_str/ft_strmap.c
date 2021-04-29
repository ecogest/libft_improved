/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:26:53 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 20:06:30 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3))
** resulting from the successive applications of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*d;

	if (!s)
		return (NULL);
	d = malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!d)
		return (NULL);
	i = -1;
	while (s[++i])
		d[i] = f(s[i]);
	d[i] = '\0';
	return (d);
}
