/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:45:42 by mjacq             #+#    #+#             */
/*   Updated: 2020/12/03 12:10:31 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>

# define FT_MASK_1BIT	0x1
# define FT_MASK_2BIT	0x3
# define FT_MASK_3BIT	0x7
# define FT_MASK_4BIT	0xF
# define FT_MASK_5BIT	0x1F
# define FT_MASK_6BIT	0x3F
# define FT_MASK_7BIT	0x7F
# define FT_MASK_8BIT	0xFF
# define FT_MASK_11BIT	0x7FF
# define FT_MASK_16BIT	0xFFFF
# define FT_MASK_21BIT	0x1FFFFF
# define FT_MASK_24BIT	0xFFFFFF
# define FT_MASK_32BIT	0xFFFFFFFF

typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

/*
** t_op is the optimal size handled by the proc
** on a 64bit proc it is int64_t, (long in linux)
** used in ft_memset
*/

typedef int64_t	t_op;

/*
** Part I
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, \
		size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);
int					ft_atoi(const char *str);

char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);

/*
** Part II
*/

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Bonus
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new_lst_elem);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new_lst_elem);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));

/*
** Fonctions de l'ancien sujet libft.
*/

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);

/*
** Autres fonctions
*/

int					ft_wctomb(char *s, wchar_t wc);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_putwchar(wchar_t chr);
int					ft_stris(const char *s, int (*ft_is)(int c));

/*
** Fonctions utiles dans ft_printf
*/


int					ft_abs(int x);
char				*ft_itoa_base(unsigned long long n, int base);
int					ft_max(int x, int y);
int					ft_min(int x, int y);
/* void				ft_putchar(char c); */
/* void				ft_putstr(char *s); */
/* char				*ft_strcpy(char *dst, const char *src); */
/* char				*ft_strcat(char *dst, const char *src); */

#endif
