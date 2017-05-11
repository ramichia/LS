/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:59:07 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:49:13 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		select_fonction(int conv)
{
	int		j;

	j = 0;
	if (g_data.length == 'l')
	{
		if (conv == 0)
			return (handle_wchar_string());
		else if (conv == 2)
			return (print_wchar());
	}
	if (conv == 15)
		j = display_percentage();
	else if ((3 <= conv && conv <= 11) || conv == 14)
		j = print_nbr();
	else if (conv == 0)
		j = display_string();
	else if (conv == 12)
		j = print_p();
	else if (conv == 2)
		j = print_c();
	else if (conv == 13)
		j = print_wchar();
	else if (conv == 1)
		j = handle_wchar_string();
	return (j);
}

void	initiate_data(int conv, char *tmp, va_list *arg)
{
	char		length;

	length = find_length(tmp, 0);
	if (conv == 0 && length == 'l')
		stock_format_wchar_string(tmp, arg, 0);
	else if (conv == 2 && length == 'l')
		stock_format_wchar(tmp, arg);
	else if (conv == 0)
		stock_format_string(tmp, arg);
	else if (conv == 1)
		stock_format_wchar_string(tmp, arg, 0);
	else if (conv == 2)
		stock_format_char(tmp, arg);
	else if (3 <= conv && conv <= 11)
		stock_format_nbr(arg, 0);
	else if (conv == 12)
		stock_format_p(tmp, arg);
	else if (conv == 13)
		stock_format_wchar(tmp, arg);
	else if (conv == 15)
		stock_format_percentage(tmp, arg);
	else
		stock_format_undefined(tmp, arg);
}
