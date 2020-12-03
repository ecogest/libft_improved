/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:08:39 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 12:57:21 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_priv.h"

int		ft_check_for_flags(t_printf *l, va_list ap)
{
	if (ft_check_dash_flag(l) || \
			ft_check_zero_flag(l) || \
			ft_check_width_flag(l, ap) || \
			ft_check_precision_flag(l, ap))
		return (EXIT_FAILURE);
	l->fmt++;
	return (EXIT_SUCCESS);
}

int		ft_check_dash_flag(t_printf *l)
{
	if (*l->fmt == '-')
		l->flag_dash = 1;
	return (EXIT_SUCCESS);
}

int		ft_check_zero_flag(t_printf *l)
{
	if (*l->fmt == '0' && !ft_isdigit(l->fmt[-1]) && !l->flag_precision)
		l->flag_zero = 1;
	return (EXIT_SUCCESS);
}

int		ft_check_width_flag(t_printf *l, va_list ap)
{
	if (*l->fmt == '*' && !l->flag_dot)
	{
		if ((l->flag_width = va_arg(ap, int)) < 0)
			l->flag_dash |= 1;
		l->flag_width = ft_int_abs(l->flag_width);
	}
	if (ft_isdigit(*l->fmt) && !l->flag_width && !l->flag_precision)
	{
		while (ft_isdigit(*l->fmt))
			l->flag_width = l->flag_width * 10 + *l->fmt++ - '0';
		l->fmt--;
	}
	return (EXIT_SUCCESS);
}

int		ft_check_precision_flag(t_printf *l, va_list ap)
{
	if (*l->fmt == '.')
	{
		l->flag_dot = 1;
		if (l->fmt[1] == '*')
			l->flag_precision = va_arg(ap, int);
		while (ft_isdigit(l->fmt[1]))
			l->flag_precision = l->flag_precision * 10 + *++l->fmt - '0';
	}
	return (EXIT_SUCCESS);
}
