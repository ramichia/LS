/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:44:41 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:50:01 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_base_binary(uintmax_t nbr, int base)
{
	char	*tmp;
	char	*str;
	int		size;
	int		modulo;
	int		i;

	if (nbr == 0)
		return ("0");
	size = malloc_size(nbr, base);
	tmp = ft_strnew(size + 1);
	i = 0;
	while (0 < nbr)
	{
		modulo = nbr % base;
		tmp[i] = convert_hexa(modulo);
		nbr = nbr / base;
		i++;
	}
	str = ft_strrev(tmp);
	ft_strdel(&tmp);
	return (str);
}

int		convert_binary(char *str)
{
	int		result;
	char	*tmp2;
	int		tmp;
	char	*binary;
	char	*tmp3;

	tmp3 = ft_strnew(8);
	if (str[0] == '0')
		tmp3 = ft_strcpy(tmp3, &str[1]);
	else
		tmp3 = ft_strcpy(tmp3, str);
	result = 0;
	binary = ft_strdup("");
	while (ft_strcmp(binary, tmp3) != 0)
	{
		tmp2 = convert_base_binary(result, 2);
		tmp = ft_atoi(tmp2);
		binary = ft_itoa(tmp);
		result++;
	}
	result--;
	ft_strdel(&tmp2);
	ft_strdel(&binary);
	ft_strdel(&tmp3);
	return (result);
}

void	stock_format_wchar_string(char *str, va_list *arg, int i)
{
	g_data.flag = 1;
	g_data.wchar_string = va_arg(*arg, wchar_t*);
	g_data.space = ' ';
	while (matchf(str[i]) < 5)
	{
		if (matchf(str[i]) == 0)
			g_data.flag = 0;
		if (matchf(str[i]) == 4 && g_data.flag != 0)
			g_data.space = '0';
		i++;
	}
	g_data.size_min = stock_size(&str[i], arg);
	i = i_forward(str, i);
	g_data.precision = -1;
	if (str[i] == '.')
		g_data.precision = stock_size(&str[i + 1], arg);
}

char	*transform_wchar(wchar_t *wstr)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*ret;

	i = 0;
	ret = ft_strnew(0);
	while (wstr[i])
	{
		tmp = handle_wchar(wstr[i]);
		tmp2 = ft_strjoin(ret, tmp);
		ft_strdel(&ret);
		ft_strdel(&tmp);
		ret = tmp2;
		i++;
	}
	return (ret);
}

int		handle_wchar_string(void)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	if (g_data.wchar_string != NULL)
	{
		tmp = transform_wchar(g_data.wchar_string);
		size = wcharlen(g_data.wchar_string);
		free(g_data.to_display);
		g_data.to_display = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
	{
		free(g_data.to_display);
		g_data.to_display = ft_strdup("(null)");
	}
	return (display_string());
}
