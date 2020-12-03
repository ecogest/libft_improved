/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:19:36 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/08 18:02:57 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	while (*lst)
	{
		t = (*lst)->next;
		(*lst)->next = NULL;
		del((*lst)->content);
		free(*lst);
		*lst = t;
	}
}
