/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:43:25 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:49:37 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_min_c(char *str, va_list *arg, int i)
{
	int		size_min;

	size_min = stock_size(&str[i], arg);
	if (size_min == 0)
		size_min = size_min + 1;
	return (size_min);
}

void	stock_format_char(char *str, va_list *arg)
{
	int			i;

	g_data.size_min = 0;
	g_data.flag = 1;
	g_data.space = ' ';
	g_data.length = find_length(str, 0);
	i = 0;
	while (matchf(str[i]) < 7)
	{
		if (matchf(str[i]) == 0)
			g_data.flag = 0;
		if (matchf(str[i]) == 4)
			g_data.space = '0';
		i++;
	}
	g_data.size_min = size_min_c(str, arg, i);
	g_data.c = (unsigned char)va_arg(*arg, int);
	i = i_forward(str, i);
	g_data.to_display[0] = g_data.c;
	if (g_data.c == 0)
		g_data.size_min--;
}

int		print_c(void)
{
	int		r;

	if (g_data.length == 'l')
		return (print_wchar());
	else
	{
		if (g_data.c == 0)
		{
			if (g_data.flag == 0)
			{
				ft_putchar(g_data.c);
				r = min_size_str_minus();
			}
			else
			{
				r = min_size_str();
				ft_putchar(g_data.c);
			}
			return (1 + r);
		}
		return (print_string());
	}
}
