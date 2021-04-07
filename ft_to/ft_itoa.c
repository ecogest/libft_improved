/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:56:51 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/07 19:09:42 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert int to string.
*/

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
		s[j] = '0' + ft_int_abs(n % 10);
		n /= 10;
	}
	if (i < 0)
		s[0] = '-';
	return (s);
}
