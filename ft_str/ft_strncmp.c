/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:31:13 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 20:08:23 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n)
	{
		s1++;
		s2++;
		n--;
	}
	if (n)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
		return (0);
}
