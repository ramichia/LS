/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:40:19 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:45:36 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_g_data(void)
{
	if (g_data.format)
		ft_strdel(&g_data.format);
	if (g_data.to_display)
		ft_strdel(&g_data.to_display);
	if (g_data.sign)
		ft_strdel(&g_data.sign);
	if (g_data.hash_key)
		ft_strdel(&g_data.hash_key);
}

void	initiate_iteration(void)
{
	g_data.to_display = ft_strnew(1);
	g_data.hash_key = ft_strnew(1);
	g_data.ret = 0;
}

void	handle_return(int *j, int *i)
{
	if (g_data.conv != 17)
		*j = *j + select_fonction(g_data.conv);
	if (g_data.conv != 17)
		*i = *i + ft_strlen(g_data.format);
}

int		iterate_string(char *str, va_list *arg, int i, int j)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i++])
				return (j);
			initiate_iteration();
			g_data.format = get_format(&str[i], &i);
			g_data.conv = find_conv(g_data.format);
			g_data.length = find_length(g_data.format, 0);
			initiate_data(g_data.conv, g_data.format, arg);
			if (g_data.conv == 17)
			{
				if (!str[i])
					break ;
				j = j + display_undefined(str, i);
				i++;
			}
			handle_return(&j, &i);
			free_g_data();
		}
		else
			putchar_printf(str, &i, &j);
	}
	return (j);
}

int		ft_printf(char *str, ...)
{
	va_list	args;
	int		r;

	va_start(args, str);
	r = iterate_string(str, &args, 0, 0);
	va_end(args);
	return (r);
}
