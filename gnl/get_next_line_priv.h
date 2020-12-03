/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_priv.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:04:51 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 13:06:10 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PRIV_H
# define GET_NEXT_LINE_PRIV_H

# include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

# define ERROR		-1
# define COMPLETE	1
# define ONGOING	2
# define END		0

int				ft_char_to_copy(char buf[]);
int				ft_alloc_line(char **line, int ctc);
void			ft_concat_line_buffer(char *line, char buf[], int ctc);
int				ft_buffer_shift(char buf[], unsigned int shift);
unsigned int	ft_strlen2(char *str);

#endif
