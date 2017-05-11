/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:52:37 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:50:03 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	flag_p(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (matchf(str[i]) == 4)
			return ('0');
		i++;
	}
	return (' ');
}

void	stock_format_p(char *str, va_list *arg)
{
	int			i;
	char		*tmp;

	i = 0;
	g_data.space = flag_p(str);
	g_data.conv = match_conversion(str[ft_strlen(str) - 1]);
	g_data.flag = get_int_flag(str, g_data.conv, 7, 0);
	free(g_data.hash_key);
	g_data.hash_key = ft_strdup("0x");
	g_data.flag_zero = 1;
	while (matchf(str[i]) < 6)
		i++;
	g_data.size_min = stock_size(&str[i], arg);
	i = i_forward(str, i);
	convert_base2((uintmax_t)va_arg(*arg, void*), 16);
	if (str[i] == '.')
	{
		g_data.precision = stock_size_precision(&str[i + 1], arg);
		precision_nbr(g_data.to_display, g_data.precision);
	}
	tmp = g_data.to_display;
	g_data.to_display = ft_strjoin(g_data.hash_key, g_data.to_display);
	ft_strdel(&tmp);
}

int		print_p(void)
{
	if (g_data.flag == 0)
		return (min_size_str_minus());
	if (g_data.flag == 7 && g_data.space == '0')
		return (min_size_str_minus());
	else
		return (min_size_str());
}
