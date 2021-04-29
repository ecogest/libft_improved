/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max_abs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:16:56 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 20:23:14 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_int_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	ft_int_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int	ft_int_abs(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}
