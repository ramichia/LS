/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_size_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:13:51 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:48:40 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		handle_null(void)
{
	ft_putstr("(null)");
	return (6);
}

int		min_size_str(void)
{
	char	*tmp;
	int		i;
	int		j;

	if (g_data.to_display == NULL)
		return (handle_null());
	if ((int)ft_strlen(g_data.to_display) <= g_data.size_min)
	{
		tmp = ft_strnew(g_data.size_min);
		i = 0;
		while (i < (g_data.size_min - (int)ft_strlen(g_data.to_display)))
			tmp[i++] = g_data.space;
		j = 0;
		while (i < g_data.size_min)
		{
			tmp[i] = g_data.to_display[j];
			i++;
			j++;
		}
		ft_putstr(tmp);
		ft_strdel(&tmp);
		return (g_data.size_min);
	}
	ft_putstr(g_data.to_display);
	return (ft_strlen(g_data.to_display));
}

int		min_size_str_minus(void)
{
	char	*tmp;
	int		i;
	int		j;

	if (g_data.to_display == NULL)
		return (handle_null());
	if ((int)ft_strlen(g_data.to_display) < g_data.size_min)
	{
		tmp = ft_strnew(g_data.size_min);
		i = 0;
		j = 0;
		while (g_data.to_display[j])
		{
			tmp[i] = g_data.to_display[j];
			i++;
			j++;
		}
		while (i < g_data.size_min)
			tmp[i++] = g_data.space;
		ft_putstr(tmp);
		ft_strdel(&tmp);
		return (g_data.size_min);
	}
	ft_putstr(g_data.to_display);
	return ((int)ft_strlen(g_data.to_display));
}
