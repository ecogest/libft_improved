/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:46:47 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 12:57:21 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_priv.h"

int		ft_copy_up_to_percent(t_printf *l)
{
	int	i;

	i = 0;
	while (l->fmt[i] && l->fmt[i] != '%')
		i++;
	l->str_raw = ft_substr(l->fmt, 0, i);
	l->fmt += i;
	return (l->str_raw ? EXIT_SUCCESS : EXIT_FAILURE);
}

int		ft_parser(t_printf *l, va_list ap)
{
	int	error_ret;

	error_ret = 0;
	l->fmt++;
	while (!error_ret && *l->fmt && ft_strchr(FLAGS, *l->fmt))
		error_ret = ft_check_for_flags(l, ap);
	if (error_ret || !(*l->fmt) || !ft_strchr(CONV_SPEC, *l->fmt))
		return (EXIT_FAILURE);
	l->conv_spec = *l->fmt++;
	return (EXIT_SUCCESS);
}

int		ft_retrieve_arg(t_printf *l, va_list ap)
{
	if (l->conv_spec == 'c')
		l->u.arg_char = (unsigned char)va_arg(ap, int);
	else if (l->conv_spec == 's')
		l->u.arg_str = va_arg(ap, char *);
	else if (l->conv_spec == 'p')
		l->u.arg_voidptr = va_arg(ap, void *);
	else if (ft_strchr("diuxX", l->conv_spec))
		l->u.arg_int = va_arg(ap, int);
	else if (l->conv_spec == '%')
		l->u.arg_char = '%';
	return (EXIT_SUCCESS);
}

int		ft_convert_to_str(t_printf *l)
{
	if (ft_strchr("c%", l->conv_spec))
		l->str_raw = ft_substr((char const *)&(l->u.arg_char), 0, 1);
	else if (l->conv_spec == 's')
		l->str_raw = ft_strdup(l->u.arg_str ? l->u.arg_str : "(null)");
	else if (ft_strchr("di", l->conv_spec))
		l->str_raw = ft_itoa(l->u.arg_int);
	else if (l->conv_spec == 'u')
		l->str_raw = ft_itoa_base(l->u.arg_ullong, 10);
	else if (ft_strchr("xXp", l->conv_spec))
		l->str_raw = ft_itoa_base(l->u.arg_ullong, 16);
	if (ft_strchr("xp", l->conv_spec))
		ft_tolower_str(l->str_raw);
	return (l->str_raw ? EXIT_SUCCESS : EXIT_FAILURE);
}
