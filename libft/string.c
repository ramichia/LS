/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 16:02:49 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:49:20 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stock_format_string(char *str, va_list *arg)
{
	int			i;

	g_data.flag = 1;
	g_data.space = ' ';
	i = 0;
	while (matchf(str[i]) < 7)
	{
		if (matchf(str[i]) == 0)
			g_data.flag = 0;
		if (matchf(str[i]) == 4 && g_data.flag != 0)
			g_data.space = '0';
		i++;
	}
	g_data.size_min = stock_size(&str[i], arg);
	i = i_forward(str, i);
	if (str[i] == '.')
		g_data.precision = stock_size(&str[i + 1], arg);
	else
		g_data.precision = -1;
	ft_strdel(&g_data.to_display);
	g_data.to_display = ft_strdup(va_arg(*arg, char*));
}

void	precision_string(int nbr)
{
	char	*tmp;

	if (nbr <= 0)
	{
		free(g_data.to_display);
		g_data.to_display = ft_strdup("\0");
	}
	else
	{
		tmp = ft_strnew(nbr);
		tmp = ft_strncpy(tmp, g_data.to_display, nbr);
		free(g_data.to_display);
		g_data.to_display = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

int		print_string(void)
{
	if (g_data.flag == 0)
		return (min_size_str_minus());
	else
		return (min_size_str());
}

int		display_string(void)
{
	if (0 <= g_data.precision)
		precision_string(g_data.precision);
	return (print_string());
}
