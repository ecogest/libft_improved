/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:08:27 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 19:15:34 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates size + 1 characters and set them all to '\0'
*/

char	*ft_strnew(size_t size)
{
		return (ft_calloc(size + 1, 1));
}
