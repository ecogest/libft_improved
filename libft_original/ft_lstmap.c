/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 23:28:43 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/08 00:04:19 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*t;

	new = NULL;
	while (lst)
	{
		if (!(t = ft_lstnew(lst->content)))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		t->content = f(t->content);
		ft_lstadd_back(&new, t);
		lst = lst->next;
	}
	return (new);
}
