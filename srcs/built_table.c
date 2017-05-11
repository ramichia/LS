/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:42:49 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:08 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*handle_dirname(char *path, char *tabpath)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(path, "/");
	tmp = str;
	str = ft_strjoin(str, tabpath);
	ft_strdel(&tmp);
	return (str);
}

t_datafile	*return_error(char *path)
{
	char		*errortext;
	char		*tmp;
	t_datafile	*tab;

	tmp = ft_strdup(ft_strrchr(path, '/'));
	if (tmp == NULL)
		tmp = ft_strjoin("/", path);
	errortext = strerror(errno);
	if (ft_strcmp(&tmp[1], ".") != 0 && ft_strcmp(&tmp[1], "..") != 0)
		ft_printf("ls: %s: %s\n", &tmp[1], errortext);
	ft_strdel(&tmp);
	errno = 0;
	if (!(tab = (t_datafile*)malloc(sizeof(t_datafile) * 1)))
		return (NULL);
	tab[0].filename = NULL;
	return (tab);
}

t_datafile	*fill_table_file(char *path)
{
	t_datafile		*tab;

	errno = 0;
	if (!(tab = (t_datafile*)malloc(sizeof(t_datafile) * 2)))
		return (NULL);
	tab[0] = stock_data(path);
	if (tab[0].filename == NULL)
		return_error(path);
	else
	{
		tab[1].filename = NULL;
		replace_name(tab);
		display_tab(tab);
	}
	return (tab);
}

t_datafile	*fill_table(char *path)
{
	struct dirent	*readir;
	DIR				*dir;
	t_datafile		*tab;
	int				i;
	char			*tmp;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
		return (return_error(path));
	errno = 0;
	tab = (t_datafile*)malloc(sizeof(t_datafile) * (malloc_tab(path) + 1));
	readir = readdir(dir);
	while (readir)
	{
		tmp = handle_dirname(path, readir->d_name);
		tab[i] = stock_data(tmp);
		ft_strdel(&tmp);
		readir = readdir(dir);
		i++;
	}
	tab[i].filename = NULL;
	end_fill(dir, tab);
	return (tab);
}

t_datafile	*fill_table_rec(char *path, int count)
{
	t_datafile		*tab;
	t_datafile		*tab2;
	int				i;

	i = 0;
	tab = fill_table(path);
	while (tab[i].filename)
	{
		if (tab[i].mode[0] == 'd' && ft_strcmp(tab[i].filename, ".") != 0 \
			&& ft_strcmp(tab[i].filename, "..") != 0 && g_flag_int.opt[4] == 1)
		{
			ft_printf("\n%s:\n", tab[i].path);
			tab2 = fill_table_rec(tab[i].path, count);
			free_tab(tab2);
		}
		else if (tab[i].mode[0] == 'd' && tab[i].filename[0] != '.')
		{
			ft_printf("\n%s:\n", tab[i].path);
			tab2 = fill_table_rec(tab[i].path, count);
			free_tab(tab2);
		}
		i++;
	}
	return (tab);
}
