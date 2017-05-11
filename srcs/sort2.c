/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:48:33 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:47 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	swap_ascii(t_datafile *tab, int i)
{
	t_datafile	tmp;

	if (tab[i + 1].filename && \
		ft_strcmp(tab[i].filename, tab[i + 1].filename) > 0)
	{
		tmp = tab[i + 1];
		tab[i + 1] = tab[i];
		tab[i] = tmp;
	}
}

void	sort_time(t_datafile *tab)
{
	int			i;
	int			j;
	t_datafile	tmp;

	j = 0;
	while (tab[j].filename)
	{
		i = 0;
		while (tab[i].filename)
		{
			if (tab[i + 1].filename && \
				tab[i].time_modif < tab[i + 1].time_modif)
			{
				tmp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = tmp;
			}
			else if (tab[i].time_modif == tab[i + 1].time_modif)
				swap_ascii(tab, i);
			i++;
		}
		j++;
	}
}

void	sort_rev(t_datafile *tab)
{
	int			i;
	int			j;
	t_datafile	tmp;

	i = 0;
	j = 0;
	while (tab[i].filename)
		i++;
	i--;
	while (j <= i)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i--;
		j++;
	}
}

void	sort_tab_struct(t_datafile *tab)
{
	if (g_flag_int.opt[6] == 1)
		sort_tab_ascii(tab);
	else if (g_flag_int.opt[3] == 1 && g_flag_int.opt[2] == 0)
		sort_time(tab);
	else if (g_flag_int.opt[3] == 1 && g_flag_int.opt[2] == 1)
	{
		sort_time(tab);
		sort_rev(tab);
	}
	else if (g_flag_int.opt[2] == 0)
		sort_tab_ascii(tab);
	else if (g_flag_int.opt[2] == 1)
		sort_tab_ascii_rev(tab);
}

void	sort_tab_ascii_rev(t_datafile *tab)
{
	int			i;
	t_datafile	tmp;

	i = 0;
	while (tab[i].filename)
	{
		if (tab[i + 1].filename && ft_strcmp(tab[i].filename, \
			tab[i + 1].filename) < 0)
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
		}
		i++;
		if (!tab[i + 1].filename && !ft_issort_struct_rev(tab))
			i = 0;
	}
}
