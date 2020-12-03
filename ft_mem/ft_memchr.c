/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:48:21 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/09 14:33:27 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*t;
	unsigned char		d;

	t = s;
	d = c;
	if (n == 0)
		return (NULL);
	while (--n && *t != d)
		t++;
	return (*t == d ? (void *)t : NULL);
}
