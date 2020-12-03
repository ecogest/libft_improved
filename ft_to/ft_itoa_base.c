/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:57:25 by mjacq             #+#    #+#             */
/*   Updated: 2019/12/07 12:57:22 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** On utilise un double car les adresses (pointeurs) à convertir en hexa
** dépassent la taille d'un int ou d'un unsigned int.
*/

char	*ft_itoa_base(unsigned long long n, int base)
{
	char				*base_char;
	char				*ret;
	int					len_nbr;
	unsigned long long	n_cpy;

	if (base > 16 || base < 2)
		return (NULL);
	base_char = "0123456789ABCDEF";
	n_cpy = n;
	len_nbr = 1;
	while (n_cpy /= base)
		len_nbr++;
	if (!(ret = (char *)malloc(sizeof(char) * (len_nbr + 1))))
		return (NULL);
	ret[len_nbr] = '\0';
	while (len_nbr--)
	{
		ret[len_nbr] = base_char[n % (unsigned long long)base];
		n /= (unsigned long long)base;
	}
	return (ret);
}
