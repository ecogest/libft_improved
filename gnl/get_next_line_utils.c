/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:34:12 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 20:38:47 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_priv.h"

int	ft_char_to_copy(char buf[])
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
		if (buf[i] == '\0' || buf[i] == '\n')
			break ;
	return (i);
}

int	ft_alloc_line(char **line, int ctc)
{
	int		i;
	char	*temp;

	temp = *line;
	*line = (char *)malloc(sizeof(char) * (ctc + ft_strlen2(*line) + 1));
	if (!*line)
		return (ERROR);
	i = -1;
	while (temp[++i])
		(*line)[i] = temp[i];
	(*line)[i] = '\0';
	free(temp);
	return (0);
}

void	ft_concat_line_buffer(char *line, char buf[], int ctc)
{
	while (*line)
		line++;
	while (ctc--)
		*line++ = *buf++;
	*line = '\0';
}

int	ft_buffer_shift(char buf[], unsigned int shift)
{
	int	i;
	int	ret;

	if (shift < BUFFER_SIZE && buf[shift] == '\n')
		ret = COMPLETE;
	else
		ret = ONGOING;
	shift += (ret == COMPLETE);
	i = 0;
	while (shift + i < BUFFER_SIZE && buf[shift + i])
	{
		buf[i] = buf[shift + i];
		i++;
	}
	buf[i] = '\0';
	return (ret);
}

unsigned int	ft_strlen2(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
