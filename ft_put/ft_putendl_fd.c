/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:30:11 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/07 12:07:18 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Put string and '\n' to specified file descriptor.
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (fd == -1 || s == NULL)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
