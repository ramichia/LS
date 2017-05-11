/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:52:12 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:21 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	initiate_fileinfo(t_datafile fileinfo)
{
	fileinfo.last_change = ft_strnew(0);
	fileinfo.username = ft_strnew(0);
	fileinfo.usergroup = ft_strnew(0);
	fileinfo.path = ft_strnew(0);
	fileinfo.filename = ft_strnew(0);
}

void	free_fileinfo(t_datafile fileinfo)
{
	ft_strdel(&fileinfo.last_change);
	ft_strdel(&fileinfo.username);
	ft_strdel(&fileinfo.usergroup);
	ft_strdel(&fileinfo.path);
	ft_strdel(&fileinfo.filename);
	ft_strdel(&fileinfo.link);
}

void	free_tab(t_datafile *tab)
{
	int		i;

	i = 0;
	if (tab[i].filename == NULL)
		return ;
	while (tab[i].filename)
	{
		free_fileinfo(tab[i]);
		i++;
	}
	free(tab);
}

void	free_char_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

void	end_fill(DIR *dir, t_datafile *tab)
{
	closedir(dir);
	sort_tab_struct(tab);
	display_tab(tab);
}
