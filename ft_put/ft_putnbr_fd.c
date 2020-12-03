/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:19 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 12:16:31 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** static int	ft_abs(int x)
** {
** 	return (x > 0 ? x : -x);
** }
*/

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n / 10)
		ft_putnbr_fd(ft_abs(n / 10), fd);
	ft_putchar_fd('0' + ft_abs(n % 10), fd);
}
