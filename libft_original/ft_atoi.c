/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:43:48 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/08 17:03:53 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MIN -2147483648
#define INT_MAX 2147483647

static int	ft_isspace(char c)
{
	char	*space_list;

	space_list = " \f\n\r\t\v";
	while (*space_list && c != *space_list)
		space_list++;
	return (*space_list ? 1 : 0);
}

int			ft_atoi(const char *str)
{
	long	number;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '+' || *str == '-') ? 1 : 0;
	number = 0;
	while (*str >= '0' && *str <= '9')
		number = 10 * number + *str++ - '0';
	if (sign * number > INT_MAX || sign * number < INT_MIN)
		return (sign > 0 ? -1 : 0);
	return (sign * (int)number);
}
