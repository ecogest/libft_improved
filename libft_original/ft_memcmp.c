/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:16:08 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/06 16:18:53 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s;
	const unsigned char	*t;

	s = s1;
	t = s2;
	while (n && *s == *t)
	{
		s++;
		t++;
		n--;
	}
	return (n ? *s - *t : 0);
}
