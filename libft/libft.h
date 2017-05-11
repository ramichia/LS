/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:04:21 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:59:35 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>

# define BUFF_SIZE 2

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	int				fd;
	struct s_list	*next;
	struct s_list	*start;
}					t_list;

typedef	struct		s_format
{
	int				size_min;
	int				flag;
	int				flag_zero;
	int				precision;
	char			length;
	int				conv;
	char			space;
	char			*sign;
	int				ret;
	unsigned char	c;
	char			*hash_key;
	char			*to_display;
	wchar_t			wchar;
	wchar_t			*wchar_string;
	char			*format;
	double			data_double;
	intmax_t		nbr;
}					t_format;

static const char	g_conversions[] =
{
	's',
	'S',
	'c',
	'd',
	'D',
	'i',
	'u',
	'U',
	'o',
	'O',
	'x',
	'X',
	'p',
	'C',
	'f',
	'%'
};

static const char	g_flags_length[] =
{
	'l',
	'h',
	'j',
	'z',
	'L',
	'H'
};

static const char	g_flags[] =
{
	'-',
	'+',
	' ',
	'#',
	'0',
	'b',
	'y'
};

t_format			g_data;

char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *meule_de_foin, const char *aiguille);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int c);
intmax_t			ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_power(int c, int n);
int					*ft_range(int min, int max);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
int					ft_printf(char *str, ...);
t_list				*lst_split(char *tmp, t_list *lst, char c);
void				ft_lstadd_end(t_list *alst, t_list *new);
t_list				*create_list(int fd, t_list *lst);
int					get_next_line(const int fd, char **line);
char				*ft_strjoinfree(char *s1, char *s2);

void				convert_base(uintmax_t nbr, int base);
void				convert_base2(uintmax_t nbr, int base);
int					convert_binary(char *str);
void				print_double(int i);
void				ft_putlong(long nbr);
void				flag_hash_key(void);
void				precision_nbr(char *str, int nbr);
int					flag_print_int(void);
void				convert_int(uintmax_t nbr);
char				*handle_hash_key(void);
void				cast_nbr(va_list *arg);
int					stock_size_precision(char *str, va_list *args);
char				convert_hexa(int nbr);
int					malloc_size(uintmax_t nbr, int base);
char				handle_space(void);

int					min_size_str(void);
int					min_size_str_minus(void);
int					display_string(void);
int					print_string(void);
int					handle_wchar_string(void);
void				precision_string(int nbr);
int					wcharlen(wchar_t *str);
int					size_wchar(wchar_t w);
wchar_t				*ft_strdup_wchar(wchar_t *s);

int					print_c(void);

int					matchf(char c);
int					match_length(char c);
char				find_length(char *str, int i);
intmax_t			type_to_display(char *str, va_list *args);
int					get_int_flag(char *str, int conv, int flag, int i);

int					print_nbr(void);
int					handle_c(va_list *arg, char *str, int conv);
char				*handle_wchar(wchar_t t);
int					handle_options_wchar(char *str, va_list *arg);
char				*match_mask(char *str);
char				*change_mask(char *mask, char *str);
int					print_wchar(void);
char				*handle_wchar(wchar_t wchar);

char				*get_format(char *str, int *i);
int					stock_size(char *str, va_list	*args);

int					print_p(void);
int					display_percentage(void);
int					display_undefined(char *str, int i);
void				handle_undefined(char *str, int *i, int *j);

void				stock_format_undefined(char *str, va_list *arg);
void				stock_format_p(char	*str, va_list *arg);
void				stock_format_string(char *str, va_list *arg);
void				stock_format_wchar(char *str, va_list *arg);
void				stock_format_char(char *str, va_list *arg);
void				stock_format_wchar_string(char *str, va_list *arg, int i);
void				stock_format_nbr(va_list *arg, int i);
void				stock_format_percentage(char *str, va_list *arg);
void				stock_format_float(va_list *arg, int i);
int					select_fonction(int conv);
void				initiate_data(int conv, char *tmp, va_list *arg);

int					match_conversion(char c);
int					i_forward(char *str, int i);
int					find_conv(char	*tmp);
void				putchar_printf(char	*str, int *i, int *j);
int					wcharlen(wchar_t *str);
int					ft_printf(char *str, ...);
int					iterate_string(char *str, va_list *arg, int i, int j);
#endif
