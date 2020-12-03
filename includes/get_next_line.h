/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:46:07 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 10:55:46 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

# define ERROR		-1
# define COMPLETE	1
# define ONGOING	2
# define END		0

int				get_next_line(int fd, char **line);
int				ft_char_to_copy(char buf[]);
int				ft_alloc_line(char **line, int ctc);
void			ft_concat_line_buffer(char *line, char buf[], int ctc);
int				ft_buffer_shift(char buf[], unsigned int shift);
unsigned int	ft_strlen2(char *str);

#endif
