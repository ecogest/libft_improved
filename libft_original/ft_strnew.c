/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:08:27 by mjacq             #+#    #+#             */
/*   Updated: 2020/07/01 11:33:45 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.
** Each character of the string is initialized at ’\0’.
** If the allocation fails the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	if (!size)
		return (NULL);
	else
		return (ft_calloc(size + 1, 1));
}
