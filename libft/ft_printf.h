/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:12:15 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:35:23 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

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

t_format			g_data;

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

#endif
