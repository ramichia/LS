/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:24:25 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:48:49 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stock_format_nbr(va_list *arg, int i)
{
	g_data.sign = ft_strdup("+");
	g_data.flag_zero = 0;
	g_data.flag = get_int_flag(g_data.format, g_data.conv, 7, 0);
	while (matchf(g_data.format[i]) < 7)
	{
		if (matchf(g_data.format[i]) == 4 && g_data.flag != 0 \
			&& g_data.flag != 5 && g_data.flag != 6)
			g_data.flag_zero = 1;
		i++;
	}
	g_data.size_min = stock_size(&g_data.format[i], arg);
	i = i_forward(g_data.format, i);
	if (g_data.format[i] == '.')
	{
		g_data.precision = stock_size_precision(&g_data.format[i + 1], arg);
		cast_nbr(arg);
		precision_nbr(g_data.to_display, g_data.precision);
		if (g_data.precision != 0)
			g_data.flag_zero = 0;
	}
	else
		cast_nbr(arg);
	g_data.space = handle_space();
	flag_hash_key();
}

void	handle_flag_2(void)
{
	char	*tmp2;
	char	*tmp3;

	if (g_data.flag_zero == 0)
	{
		tmp2 = ft_strjoin(g_data.hash_key, g_data.to_display);
		if (g_data.sign[0] == '-')
		{
			tmp3 = tmp2;
			tmp2 = ft_strjoin(g_data.sign, g_data.to_display);
			ft_strdel(&tmp3);
		}
	}
	else
	{
		ft_putstr(g_data.hash_key);
		if (g_data.sign[0] == '-')
			tmp2 = ft_strjoin(g_data.sign, g_data.to_display);
		else
			tmp2 = ft_strdup(g_data.to_display);
		g_data.ret = g_data.ret + ft_strlen(g_data.hash_key);
		g_data.size_min = g_data.size_min - ft_strlen(g_data.hash_key);
	}
	free(g_data.to_display);
	g_data.to_display = tmp2;
}

void	handle_conv_signed(void)
{
	char	*tmp2;
	char	*tmp3;

	if (g_data.flag == 2)
		handle_flag_2();
	else if ((g_data.flag == 1 || g_data.sign[0] == '-') \
		&& g_data.flag_zero == 0)
	{
		tmp2 = ft_strjoin(g_data.sign, g_data.to_display);
		tmp3 = ft_strjoin(g_data.hash_key, tmp2);
		free(g_data.to_display);
		g_data.to_display = ft_strdup(tmp3);
		ft_strdel(&tmp2);
		ft_strdel(&tmp3);
	}
	else if (g_data.flag == 1 || g_data.flag == 6 || g_data.sign[0] == '-')
	{
		ft_putstr(g_data.sign);
		g_data.ret++;
		g_data.size_min--;
	}
}

void	handle_conv_unsigned(void)
{
	char	*tmp2;

	if (g_data.flag_zero == 0)
	{
		tmp2 = ft_strjoin(g_data.hash_key, g_data.to_display);
		free(g_data.to_display);
		g_data.to_display = ft_strdup(tmp2);
		ft_strdel(&tmp2);
	}
	else
	{
		ft_putstr(g_data.hash_key);
		g_data.ret = g_data.ret + ft_strlen(g_data.hash_key);
		g_data.size_min = g_data.size_min - ft_strlen(g_data.hash_key);
	}
}

int		print_nbr(void)
{
	if (3 <= g_data.conv && g_data.conv <= 5)
		handle_conv_signed();
	else if (6 < g_data.conv)
		handle_conv_unsigned();
	if (g_data.flag == 0 || g_data.flag == 5 || g_data.flag == 6)
		return (g_data.ret + min_size_str_minus());
	return (g_data.ret + min_size_str());
}
