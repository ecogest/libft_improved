/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:37:32 by mjacq             #+#    #+#             */
/*   Updated: 2020/01/06 19:03:35 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_parse_and_get_arg(t_printf *link, va_list ap)
{
	int	err;

	if (*link->fmt && *link->fmt != '%')
		err = ft_copy_up_to_percent(link);
	else
	{
		err = ft_parser(link, ap) ||
			ft_retrieve_arg(link, ap) ||
			ft_convert_to_str(link);
	}
	return (!err ? EXIT_SUCCESS : EXIT_FAILURE);
}

static int	ft_format(t_printf *l)
{
	int	err;

	err = 0;
	if (l->flag_dot && !(l->flag_precision < 0 || l->conv_spec == 'c'))
		err = ft_apply_precision(l);
	if (!err && l->conv_spec == 'p')
		err = ft_apply_pointer_prefix(l);
	if (!err && l->flag_width > (int)ft_strlen(l->str_raw))
		err = ft_padding(l);
	return (!err ? EXIT_SUCCESS : EXIT_FAILURE);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_printf	*link;
	int			len;
	int			err;

	err = (fmt == NULL);
	link = NULL;
	va_start(ap, fmt);
	while (!err && *fmt)
	{
		err = ft_lst_add_link(&link, (char *)fmt) ||
			ft_parse_and_get_arg(link, ap) ||
			ft_format(link);
		!err ? fmt = link->fmt : (void)0;
	}
	va_end(ap);
	!err ? len = ft_lst_printf(link) : (void)0;
	ft_lst_clean(&link);
	return (!err ? len : EXIT_FAILURE);
}
