/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:43:16 by mjacq             #+#    #+#             */
/*   Updated: 2019/12/09 18:40:37 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define CONV_SPEC			"cspdiuxX%"
# define FLAGS				"-0123456789.*"

typedef struct				s_printf
{
	char					*fmt;
	char					conv_spec;
	int						flag_dash;
	int						flag_zero;
	int						flag_width;
	int						flag_dot;
	int						flag_precision;
	char					*str_raw;
	char					padding_char;
	int						padding_len;
	char					*left_pad;
	char					*right_pad;
	char					*precision_pad;
	union
	{
		unsigned char		arg_char;
		char				*arg_str;
		void				*arg_voidptr;
		int					arg_int;
		unsigned long long	arg_ullong;
	}						u;
	struct s_printf			*next;
	struct s_printf			*prev;
}							t_printf;

/*
** Printf prototype
*/

int							ft_printf(const char *fmt, ...);

/*
** Some core functions
*/

int							ft_copy_up_to_percent(t_printf *link);
int							ft_parser(t_printf *link, va_list ap);
int							ft_retrieve_arg(t_printf *link, va_list ap);
int							ft_convert_to_str(t_printf *link);

/*
** Flag checking
*/

int							ft_check_for_flags(t_printf *link, va_list ap);
int							ft_check_dash_flag(t_printf *link);
int							ft_check_zero_flag(t_printf *link);
int							ft_check_width_flag(t_printf *link, va_list ap);
int							ft_check_precision_flag(t_printf *link, va_list ap);

/*
** Padding and precision
*/

int							ft_padding(t_printf *link);
int							ft_fill_pad(char **pad_ptr, char pad_char, int len);
void						ft_negative_int_padding_fix(char *pad, char *str_r);
int							ft_apply_precision(t_printf *link);
char						*ft_digit_precision(t_printf *link);

/*
** Chained list functions
*/

int							ft_lst_add_link(t_printf **link, char *fmt);
t_printf					*ft_lst_new(char *fmt);
void						ft_lst_rewind(t_printf **link);
int							ft_lst_printf(t_printf *link);
void						ft_lst_clean(t_printf **link);

/*
** Miscellaneous
*/

void						ft_tolower_str(char *str);
size_t						ft_strlen_s(const char *str);
int							ft_apply_pointer_prefix(t_printf *link);

#endif
