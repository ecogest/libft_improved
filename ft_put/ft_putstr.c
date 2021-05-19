/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:55:50 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/19 10:53:36 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** Put a string to stdout.
*/

void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}
