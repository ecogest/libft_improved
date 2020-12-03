/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:20:19 by mjacq             #+#    #+#             */
/*   Updated: 2020/07/01 09:43:42 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string passed
** as argument. Each character is passed by address to f to be
** modified if necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s)
		return ;
	while (*s)
		f(s++);
}
