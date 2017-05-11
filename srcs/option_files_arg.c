/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_files_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:02:26 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:36 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			replace_name(t_datafile *tabus)
{
	int		i;

	i = 0;
	while (tabus[i].filename)
	{
		ft_strdel(&tabus[i].filename);
		tabus[i].filename = ft_strdup(tabus[i].path);
		i++;
	}
	return (0);
}

int			stock_files_l(char **tab)
{
	int			i;
	t_datafile	*tabus;

	i = 0;
	while (tab[i])
		i++;
	if (!(tabus = (t_datafile*)malloc(sizeof(t_datafile) * (i + 1))))
		return (0);
	i = 0;
	while (tab[i])
	{
		tabus[i] = stock_data(tab[i]);
		i++;
	}
	tabus[i].filename = NULL;
	if (g_flag_int.opt[3] == 1)
		sort_time(tabus);
	if (g_flag_int.opt[2] == 1)
		sort_rev(tabus);
	replace_name(tabus);
	display_tab(tabus);
	free_tab(tabus);
	return (0);
}

t_datafile	*sort_dir_bis(char **tab, int *j)
{
	int			i;
	t_datafile	*tabus;

	i = 0;
	while (tab[i])
		i++;
	if (!(tabus = (t_datafile*)malloc(sizeof(t_datafile) * (i + 1))))
		return (NULL);
	i = 0;
	errno = 0;
	while (tab[i])
	{
		tabus[i] = stock_data(tab[i]);
		i++;
	}
	tabus[i].filename = NULL;
	*j = *j + i;
	return (tabus);
}

char		**sort_dir(char **tab)
{
	int			i;
	t_datafile	*tabus;
	char		**result;

	if ((g_flag_int.opt[3] == 0 && g_flag_int.opt[2] == 0) || tab[1] == NULL)
		return (tab);
	i = 0;
	tabus = sort_dir_bis(tab, &i);
	if (!(result = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	if (g_flag_int.opt[3] == 1)
		sort_time(tabus);
	if (g_flag_int.opt[2] == 1)
		sort_rev(tabus);
	i = 0;
	while (tabus[i].filename)
	{
		result[i] = tabus[i].path;
		i++;
	}
	result[i] = NULL;
	free_char_tab(tab);
	return (result);
}
