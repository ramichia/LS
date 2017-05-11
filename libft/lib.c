/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:01:23 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:50:16 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		match_conversion(char c)
{
	int		i;

	i = 0;
	while (g_conversions[i] && g_conversions[i] != c)
		i++;
	return (i);
}

int		i_forward(char *str, int i)
{
	if (str[i] == '*')
	{
		i++;
		return (i);
	}
	while ((('0' <= str[i]) && (str[i] <= '9')) || str[i] == '*')
		i++;
	return (i);
}

int		find_conv(char *tmp)
{
	int		conv;

	conv = match_conversion(tmp[ft_strlen(tmp) - 1]);
	return (conv);
}

void	putchar_printf(char *str, int *i, int *j)
{
	if (str[*i])
	{
		ft_putchar(str[*i]);
		*i = *i + 1;
		*j = *j + 1;
	}
}

int		wcharlen(wchar_t *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		count = count + size_wchar(str[i]);
		i++;
	}
	return (count + 1);
}
