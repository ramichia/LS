/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:39:39 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:50:02 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stock_format_percentage(char *str, va_list *arg)
{
	int			i;

	i = 0;
	g_data.flag = 1;
	g_data.size_min = 0;
	g_data.space = ' ';
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
	g_data.to_display[0] = '%';
}

int		display_percentage(void)
{
	return (print_string());
}
