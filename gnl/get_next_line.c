/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:56:00 by mjacq             #+#    #+#             */
/*   Updated: 2019/11/19 20:20:09 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_copy_buffer_line(char buf[], char **line, int ret_read)
{
	int		ctc;

	if (ret_read < BUFFER_SIZE)
		buf[ret_read] = '\0';
	ctc = ft_char_to_copy(buf);
	if (ft_alloc_line(line, ctc) == ERROR)
		return (ERROR);
	ft_concat_line_buffer(*line, buf, ctc);
	return (ft_buffer_shift(buf, ctc));
}

int			get_next_line(int fd, char **line)
{
	int				ret_read;
	int				ret_copy;
	static char		buf[BUFFER_SIZE];

	if (!(line) || fd < 0)
		return (ERROR);
	*line = (char *)malloc(sizeof(char));
	**line = '\0';
	if (*buf)
		if ((ret_copy = ft_copy_buffer_line(buf, line, BUFFER_SIZE)) != ONGOING)
			return (ret_copy);
	while ((ret_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret_read == ERROR)
			return (ERROR);
		if ((ret_copy = ft_copy_buffer_line(buf, line, ret_read)) != ONGOING)
			return (ret_copy);
	}
	return (END);
}
