/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:57:55 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/06 12:59:27 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_memcpy_bwd(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (len--)
		d[len] = s[len];
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
		return (ft_memcpy_bwd(dst, src, len));
	return (dst);
}
