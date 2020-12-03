/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:55:15 by mjacq             #+#    #+#             */
/*   Updated: 2020/07/01 09:48:31 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = ft_calloc(size, 1)))
		return (NULL);
	else
		return (mem);
}
