/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:18:08 by mjacq             #+#    #+#             */
/*   Updated: 2020/07/01 10:50:25 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets every character of the string to the value ’\0’.
*/

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	while (*s)
		*s++ = '\0';
}