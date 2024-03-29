/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:43:48 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/07 14:27:17 by mjacq            ###   ########.fr       */
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
** Convert string to int.
** Positive long overflows (> LONG_MAX) return (-1), negative (< LONG_MIN) (0)
*/

int	ft_atoi(const char *str)
{
	unsigned long	number;
	int				sign;

	while (atoi_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = 10 * number + *str++ - '0';
		if (sign > 0 && number > LONG_MAX)
			return (-1);
		if (sign < 0 && number > (unsigned long)LONG_MAX + 1)
			return (0);
	}
	return (sign * (int)number);
}

/*
** #include <stdlib.h>
** int	main(void) {
** 	ft_putnbr(atoi("-2147483646"));
** 	ft_putchar('\n');
** 	ft_putnbr(ft_atoi("-2147483646"));
** 	ft_putchar('\n');
** 	ft_putchar('\n');
** 	ft_putnbr(atoi("-2147483647"));
** 	ft_putchar('\n');
** 	ft_putnbr(ft_atoi("-2147483647"));
** 	ft_putchar('\n');
** 	ft_putchar('\n');
** 	ft_putnbr(atoi("-2147483648"));
** 	ft_putchar('\n');
** 	ft_putnbr(ft_atoi("-2147483647"));
** 	ft_putchar('\n');
** 	ft_putchar('\n');
** 	ft_putnbr(atoi("-2147483649"));
** 	ft_putchar('\n');
** 	ft_putnbr(ft_atoi("-2147483649"));
** 	ft_putchar('\n');
** 	ft_putchar('\n');
** 	ft_putnbr(atoi("99999999999999999999999999"));
** 	ft_putchar('\n');
** 	ft_putnbr(ft_atoi("99999999999999999999999999"));
** 	ft_putchar('\n');
** 	ft_putchar('\n');
** 	ft_putnbr(atoi("-99999999999999999999999999"));
** 	ft_putchar('\n');
** 	ft_putnbr(ft_atoi("-99999999999999999999999999"));
** 	ft_putchar('\n');
** 	ft_putchar('\n');
** 	return (0);
** }
*/
