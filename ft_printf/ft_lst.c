/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:59:43 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 12:57:21 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_priv.h"

int			ft_lst_add_link(t_printf **link, char *fmt)
{
	t_printf	*new;

	if (!(new = ft_lst_new(fmt)))
		return (EXIT_FAILURE);
	if (!(*link))
		*link = new;
	else
	{
		(*link)->next = new;
		(*link)->next->prev = *link;
		*link = (*link)->next;
	}
	return (EXIT_SUCCESS);
}

t_printf	*ft_lst_new(char *fmt)
{
	t_printf	*new;

	if (!(new = (t_printf *)malloc(sizeof(*new))))
		return (NULL);
	ft_bzero(new, sizeof(*new));
	new->fmt = fmt;
	return (new);
}

void		ft_lst_rewind(t_printf **link)
{
	if (!(*link))
		return ;
	while ((*link)->prev)
		*link = (*link)->prev;
}

int			ft_lst_printf(t_printf *link)
{
	int	printed_char;

	printed_char = 0;
	ft_lst_rewind(&link);
	while (link)
	{
		ft_putstr(link->left_pad);
		ft_putstr(link->str_raw);
		if (link->conv_spec == 'c' && link->u.arg_char == '\0')
		{
			write(1, "", 1);
			printed_char += 1;
		}
		ft_putstr(link->right_pad);
		printed_char += ft_strlen(link->str_raw) + \
						ft_strlen_s(link->left_pad) + \
						ft_strlen_s(link->right_pad);
		link = link->next;
	}
	return (printed_char);
}

void		ft_lst_clean(t_printf **link)
{
	t_printf	*tmp;

	ft_lst_rewind(link);
	while (*link)
	{
		tmp = *link;
		*link = (*link)->next;
		(tmp->str_raw ? free(tmp->str_raw) : (void)0);
		(tmp->left_pad ? free(tmp->left_pad) : (void)0);
		(tmp->right_pad ? free(tmp->right_pad) : (void)0);
		(tmp->precision_pad ? free(tmp->precision_pad) : (void)0);
		free(tmp);
	}
}
