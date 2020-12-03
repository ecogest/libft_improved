/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 23:02:35 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 12:57:05 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_priv.h"

int		ft_apply_precision(t_printf *l)
{
	char *str_temp;

	str_temp = l->str_raw;
	if (l->conv_spec == 's')
		l->str_raw = ft_substr(l->str_raw, 0, l->flag_precision);
	if (ft_strchr("diuxXp", l->conv_spec))
		l->str_raw = ft_digit_precision(l);
	free(str_temp);
	return (l->str_raw ? EXIT_SUCCESS : EXIT_FAILURE);
}

char	*ft_digit_precision(t_printf *l)
{
	int		is_negative;
	int		src_len;
	int		diff;

	l->flag_zero = 0;
	src_len = ft_strlen(l->str_raw);
	is_negative = (*l->str_raw == '-');
	if (l->flag_precision == 0 && l->u.arg_int == 0)
		l->str_raw = "";
	if ((diff = l->flag_precision + is_negative - src_len) <= 0)
		return (ft_strdup(l->str_raw));
	if (ft_fill_pad(&l->precision_pad, '0', diff))
		return (NULL);
	ft_negative_int_padding_fix(l->precision_pad, l->str_raw);
	return (ft_strjoin(l->precision_pad, l->str_raw));
}
