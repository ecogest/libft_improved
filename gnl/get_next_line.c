/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:56:00 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/12 11:47:51 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

#define GNL_BUFFER_SIZE 10

typedef enum e_gnl_return {
	e_gnl_error = -1,
	e_gnl_eol = 1,
	e_gnl_eof = 0
}	t_gnl_return;

typedef enum e_gnl_status {
	e_gnl_stat_continue,
	e_gnl_stat_stop
}	t_gnl_status;

typedef	struct s_gnl_info {
	int		fd;
	char	**line_ptr;
	char	*buf;
	t_list	*parts;
	int		error_occured;
	int		eol_reached;
	int		eof_reached;
	int		newline_reached;
}	t_gnl_info;

void	gnl_read(t_gnl_info *gnl)
{
	int	read_return;

	if (gnl->error_occured)
		return ;
	read_return = read(gnl->fd, gnl->buf, GNL_BUFFER_SIZE);
	if (read_return == -1)
		gnl->error_occured = 1;
	if (read_return < GNL_BUFFER_SIZE)
	{
		gnl->eof_reached = 1;
		gnl->buf[read_return] = '\0';
	}
}

/*
** First and last token can be of variable size,
** others should be BUFFER_SIZE long.
*/

size_t	gnl_line_len(t_gnl_info *gnl)
{
	size_t	token_count;
	size_t	line_len;

	token_count = ft_lstsize(gnl->parts);
	if (!token_count)
		return (0);
	line_len = ft_strlen(gnl->parts->content);
	if (token_count >= 2)
		line_len += ft_strlen(ft_lstlast(gnl->parts)->content);
	if (token_count > 2)
		line_len += GNL_BUFFER_SIZE * (token_count - 2);
	return (line_len);
}

void	gnl_join(t_gnl_info *gnl)
{
	size_t	line_len;
	char	*line_ptr;
	t_list	*l;

	if (gnl->error_occured)
		return ;
	line_len = gnl_line_len(gnl);
	*gnl->line_ptr = malloc(line_len + 1);
	if (!*gnl->line_ptr)
	{
		gnl->error_occured = 1;
		return;
	}
	l = gnl->parts;
	line_ptr = *gnl->line_ptr;
	*line_ptr = '\0';
	while(l)
	{
		ft_strcpy(line_ptr, l->content);
		line_ptr += ft_strlen(l->content);
		l = l->next;
	}
}

int	gnl_has_newline(t_gnl_info *gnl, size_t *newline_pos)
{
	size_t	pos;
	char	*buf;

	pos = 0;
	buf = gnl->buf;
	while (pos < GNL_BUFFER_SIZE && buf[pos])
	{
		if (buf[pos] == '\n')
		{
			gnl->eol_reached = 1;
			*newline_pos = pos;
			return (1);
		}
		pos++;
	}
	return (0);
}

/*
** Careful: the buffer is not necessarily null-terminated
*/

void	gnl_buf_to_tok(t_gnl_info *gnl)
{
	size_t	newline_pos;
	char	*token_string;
	t_list	*token;

	if (gnl_has_newline(gnl, &newline_pos))
	{
		token_string = ft_substr(gnl->buf, 0, newline_pos);
		ft_strlcpy(gnl->buf, gnl->buf + newline_pos + 1, GNL_BUFFER_SIZE - newline_pos);
	}
	else
	{
		token_string = ft_substr(gnl->buf, 0, GNL_BUFFER_SIZE);
		*gnl->buf = '\0';
	}
	token = ft_lstnew(token_string);
	if (token_string && token)
		ft_lstadd_back(&gnl->parts, token);
	else
		gnl->error_occured = 1;
}

int	gnl_has_chars_in_buffer(t_gnl_info *gnl)
{
	return (*gnl->buf != '\0');
}

int	gnl_has_to_stop(t_gnl_info *gnl)
{
	return (gnl->error_occured || gnl->eol_reached || gnl->eof_reached);
}

void	gnl_run(t_gnl_info *gnl)
{
	if (gnl->error_occured)
		return ;
	while (1)
	{
		if (gnl_has_chars_in_buffer(gnl))
			gnl_buf_to_tok(gnl);
		if (gnl_has_to_stop(gnl))
			break;
		gnl_read(gnl);
	}
	gnl_join(gnl);
}

void	init_gnl(t_gnl_info *gnl, int fd, char **line, char * buffer)
{
	ft_bzero(gnl, sizeof(*gnl));
	gnl->fd = fd;
	gnl->line_ptr = line;
	gnl->buf = buffer;
}

void	gnl_free_temp_data(t_gnl_info *gnl)
{
	ft_lstclear(&gnl->parts, free);
}

int	gnl_return(t_gnl_info *gnl)
{
	if (gnl->error_occured)
		return (e_gnl_error);
	else if (gnl->eol_reached)
		return (e_gnl_eol);
	else
		return (e_gnl_eof);
}

/*
** Return: 1 for a '\n' terminated line, 0 for the last line, -1 if err.
**
** If error, *line is set to NULL.
**
** Ex:
** - 'hello\nworld' -> [ 1: 'hello' ] , [ 0: 'world' ]
** - 'hello\n'      -> [ 1: 'hello' ] , [ 0: '' ]
** - 'hello'        -> [ 0: 'hello' ]
*/

int	get_next_line(int fd, char **line)
{
	static char	buf[GNL_BUFFER_SIZE];
	t_gnl_info	gnl;

	if (fd < 0 || !line)
		return (e_gnl_error);
	*line = NULL;
	init_gnl(&gnl, fd, line, buf);
	gnl_run(&gnl);
	gnl_free_temp_data(&gnl);
	return (gnl_return(&gnl));
}
