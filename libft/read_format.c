/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:13:05 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:49:06 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		handle_size_min(int nbr)
{
	if (nbr < 0)
	{
		g_data.flag = 0;
		nbr = -nbr;
	}
	return (nbr);
}

int		stock_size(char *str, va_list *args)
{
	int		i;
	char	*tmp;
	int		size_min;

	i = 0;
	while (('0' <= str[i] && str[i] <= '9') || str[i] == '*')
	{
		if (str[i] == '*' && ft_isdigit(str[i + 1]) != 1)
		{
			size_min = handle_size_min(va_arg(*args, int));
			return (size_min);
		}
		if (str[i] == '*' && ft_isdigit(str[i + 1]) == 1)
			va_arg(*args, int);
		i++;
	}
	if (i == 0)
		return (0);
	tmp = ft_strnew(i);
	tmp = ft_strncpy(tmp, str, i);
	size_min = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (size_min);
}

int		stock_size_precision(char *str, va_list *args)
{
	int		i;
	char	*tmp;
	int		size_min;

	i = 0;
	while (('0' <= str[i] && str[i] <= '9') || str[i] == '*')
	{
		if (str[i] == '*')
		{
			size_min = va_arg(*args, int);
			if (size_min < 0)
				size_min = 0;
			return (size_min);
		}
		i++;
	}
	tmp = ft_strnew(i);
	if (i == 0)
		return (0);
	tmp = ft_strncpy(tmp, str, i);
	size_min = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (size_min);
}

char	*get_format(char *str, int *z)
{
	int		i;
	char	*tmp;

	i = 0;
	while (15 < match_conversion(str[i]))
	{
		if (!str[i])
		{
			*z = *z + i;
			break ;
		}
		else if (6 < matchf(str[i]) && 15 < match_conversion(str[i]) && \
		3 < match_length(str[i]) && str[i] != '.' && ft_isdigit(str[i]) == 0 \
		&& str[i] != '*')
		{
			*z = *z + i;
			break ;
		}
		i++;
	}
	i++;
	tmp = ft_strnew(i);
	tmp = ft_strncpy(tmp, str, i);
	return (tmp);
}
