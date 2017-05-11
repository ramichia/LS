/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:31:05 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:18 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*handle_time(char *s)
{
	int		end;
	int		start;

	start = ft_strchr(s, ' ') - s + 1;
	end = ft_strrchr(s, ':') - s - start;
	return (ft_strsub(s, start, end));
}

void	display_no_options(t_datafile fileinfo)
{
	int		n;

	n = ft_strlen(fileinfo.path);
	if (g_flag_int.opt[4] == 1)
		colors_no_options(fileinfo, 0);
	else if (fileinfo.filename[0] != '.' && fileinfo.path[n - 1] != '.' \
		&& fileinfo.filename[0] != '.')
		colors_no_options(fileinfo, 0);
}

void	display_l_bis(t_datafile fileinfo, int sizename, int sizefile, int user)
{
	if (fileinfo.filenumber == 7)
	{
		ft_printf("%s %*d %-*s  %-9s %3d %3d  %s ", fileinfo.mode, sizename,\
		fileinfo.nb_links, user, fileinfo.username, fileinfo.usergroup, \
		fileinfo.minor, fileinfo.major, fileinfo.last_change);
		colors_no_options(fileinfo, 0);
	}
	else if (fileinfo.filenumber == 1)
		ft_printf("%s %*d %-*s  %-9s %*lld %s \033[35m%s\033[0m -> %s\n",\
		fileinfo.mode, sizename, fileinfo.nb_links, user, fileinfo.username, \
		fileinfo.usergroup, sizefile, fileinfo.size, fileinfo.last_change, \
		fileinfo.filename, fileinfo.link);
	else
	{
		ft_printf("%s %*d %-*s  %-9s %*lld %s ", fileinfo.mode, \
		sizename, fileinfo.nb_links, user, fileinfo.username, \
		fileinfo.usergroup, sizefile, fileinfo.size, fileinfo.last_change);
		colors_no_options(fileinfo, 0);
	}
}

void	display_l(t_datafile fileinfo, int sizename, int sizefile, int usersize)
{
	int		n;

	n = ft_strlen(fileinfo.path);
	if (g_flag_int.opt[4] == 1)
		display_l_bis(fileinfo, sizename, sizefile, usersize);
	else if (fileinfo.filename[0] != '.' && fileinfo.path[n - 1] != '.' \
		&& fileinfo.filename[0] != '.')
		display_l_bis(fileinfo, sizename, sizefile, usersize);
}

void	display_tab(t_datafile *tab)
{
	int		i;
	int		sizename;
	int		sizefile;
	int		usersize;

	i = 0;
	sizename = count_links_size(tab);
	sizefile = count_file_size(tab);
	usersize = count_username_size(tab);
	if (g_flag_int.opt[4] == 1 && (g_flag_int.opt[0] == 1 || \
		g_flag_int.opt[8] == 1) && tab[1].filename)
		ft_printf("total %d\n", count(tab));
	if ((g_flag_int.opt[0] == 1 || g_flag_int.opt[8] == 1) && \
		tab[1].filename && tab[2].filename)
		ft_printf("total %d\n", count(tab));
	while (tab[i].filename)
	{
		if (g_flag_int.opt[8] == 1)
			print_count(tab[i], tab);
		if (g_flag_int.opt[0] == 1)
			display_l(tab[i], sizename, sizefile, usersize);
		else
			display_no_options(tab[i]);
		i++;
	}
}
