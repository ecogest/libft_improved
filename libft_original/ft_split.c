/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:46:06 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/09 15:21:17 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_piece(char const *s, char c)
{
	int i;

	i = 0;
	while (*s++ != c)
		i++;
	return (i);
}

static int	ft_n_pieces(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	if (*s)
	{
		while (*s && *s != c)
			s++;
		return (ft_n_pieces(s, c) + 1);
	}
	return (0);
}

static char	**ft_cleartab(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		ft_bzero(t[i], ft_strlen(t[i]));
		free(t[i]);
		t[i++] = NULL;
	}
	free(t);
	t = NULL;
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**t;
	int		i;
	int		j;

	if (s == 0 || !(t = (char **)malloc(sizeof(*t) * (ft_n_pieces(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			t[i] = (char *)malloc(sizeof(**t) * (ft_len_piece(s, c) + 1));
			if (!(t[i]))
				return (ft_cleartab(t));
			j = 0;
			while (*s && *s != c)
				t[i][j++] = *s++;
			t[i][j] = '\0';
			i++;
		}
	}
	t[i] = NULL;
	return (t);
}
