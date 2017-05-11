/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_undefined.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 17:20:14 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:54:34 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stock_format_undefined(char *str, va_list *arg)
{
	int			i;

	g_data.flag = 1;
	g_data.size_min = 0;
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
}

int		display_undefined(char *str, int i)
{
	if (i < (int)ft_strlen(str))
	{
		g_data.to_display[0] = (str[i]);
		return (print_string());
	}
	else
		return (0);
}
