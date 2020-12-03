/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:02:50 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 12:57:21 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_priv.h"

void	ft_tolower_str(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}

size_t	ft_strlen_s(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

int		ft_apply_pointer_prefix(t_printf *l)
{
	char	*temp;

	temp = l->str_raw;
	l->str_raw = ft_strjoin("0x", l->str_raw);
	free(temp);
	return (l->str_raw ? EXIT_SUCCESS : EXIT_FAILURE);
}
