/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 22:10:39 by mjacq             #+#    #+#             */
/*   Updated: 2019/12/07 18:04:18 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_padding(t_printf *l)
{
	int	ret;

	l->flag_zero &= !(l->flag_dash);
	l->padding_char = (l->flag_zero ? '0' : ' ');
	l->padding_len = l->flag_width - ft_strlen(l->str_raw);
	l->padding_len -= (l->conv_spec == 'c' && l->u.arg_char == '\0');
	if (l->flag_dash)
		ret = ft_fill_pad(&l->right_pad, l->padding_char, l->padding_len);
	else
	{
		ret = ft_fill_pad(&l->left_pad, l->padding_char, l->padding_len);
		if (!ret && ft_strchr("di", l->conv_spec))
			ft_negative_int_padding_fix(l->left_pad, l->str_raw);
	}
	return (!ret ? EXIT_SUCCESS : EXIT_FAILURE);
}

int		ft_fill_pad(char **pad_ptr, char padding_char, int padding_len)
{
	if (!(*pad_ptr = (char *)malloc(sizeof(char) * (padding_len + 1))))
		return (EXIT_FAILURE);
	ft_memset(*pad_ptr, padding_char, padding_len);
	(*pad_ptr)[padding_len] = '\0';
	return (EXIT_SUCCESS);
}

void	ft_negative_int_padding_fix(char *left_pad, char *str_raw)
{
	if (left_pad[0] == '0' && str_raw[0] == '-')
	{
		left_pad[0] = '-';
		str_raw[0] = '0';
	}
}
