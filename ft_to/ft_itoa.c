/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:56:51 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/02 14:27:44 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_abs(int x)
{
	return (x > 0 ? x : -x);
}

char			*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*s;

	j = 1;
	i = n;
	while (i /= 10)
		j++;
	if (n < 0)
		j++;
	if (!(s = (char *)malloc(sizeof(*s) * (j + 1))))
		return (NULL);
	s[j] = '\0';
	i = n;
	while (j--)
	{
		s[j] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (i < 0)
		s[0] = '-';
	return (s);
}
