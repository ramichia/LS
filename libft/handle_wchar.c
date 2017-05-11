/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:09:45 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:49:57 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_wchar(wchar_t w)
{
	if (w == 0)
		return (0);
	if (w <= 0x7f)
		return (1);
	else if (w <= 0x7ff)
		return (2);
	else if (w <= 0xffff)
		return (3);
	else
		return (4);
}

char	*handle_wchar_bis(wchar_t wchar, char *tmp, int i)
{
	int		size;

	size = size_wchar(wchar);
	if (size == 1)
		tmp[i++] = wchar;
	else if (size == 2)
	{
		tmp[i++] = (wchar >> 6) + 0xC0;
		tmp[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		tmp[i++] = (wchar >> 12) + 0xE0;
		tmp[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		tmp[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		tmp[i++] = (wchar >> 18) + 0xF0;
		tmp[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		tmp[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		tmp[i++] = (wchar & 0x3F) + 0x80;
	}
	tmp[i++] = '\0';
	return (tmp);
}

char	*handle_wchar(wchar_t wchar)
{
	char	*tmp;
	int		size;

	size = size_wchar(wchar);
	tmp = ft_strnew(size + 1);
	tmp = handle_wchar_bis(wchar, tmp, 0);
	return (tmp);
}

void	stock_format_wchar(char *str, va_list *arg)
{
	int			i;

	i = 0;
	g_data.wchar = va_arg(*arg, wchar_t);
	g_data.size_min = 0;
	g_data.space = ' ';
	while (matchf(str[i]) < 5)
	{
		if (matchf(str[i]) == 0)
			g_data.flag = 1;
		i++;
	}
	g_data.size_min = stock_size(&str[i], arg);
	i = i_forward(str, i);
}

int		print_wchar(void)
{
	int		r;

	if (g_data.wchar == 0)
	{
		if (g_data.flag == 1)
		{
			ft_putchar(0);
			r = min_size_str_minus();
		}
		else
		{
			r = min_size_str();
			ft_putchar(0);
		}
		return (1 + r);
	}
	free(g_data.to_display);
	g_data.to_display = handle_wchar(g_data.wchar);
	if (g_data.flag == 1)
		return (min_size_str_minus());
	else
		return (min_size_str());
}
