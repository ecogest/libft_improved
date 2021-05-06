/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:43:48 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/06 20:30:28 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static int	atoi_isspace(char c)
{
	char	*space_list;

	space_list = " \f\n\r\t\v";
	while (*space_list && c != *space_list)
		space_list++;
	if (*space_list)
		return (1);
	else
		return (0);
}

/*
** Convert string to int. Positive overflows return (-1), negative overflows (0)
*/

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;

	while (atoi_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	number = 0;
	while (*str >= '0' && *str <= '9')
		number = 10 * number + *str++ - '0';
	if (sign * number > INT_MAX || sign * number < INT_MIN)
	{
		if (sign > 0)
			return (-1);
		else
			return (0);
	}
	else
		return (sign * (int)number);
}
