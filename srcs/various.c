/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:45:36 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:54 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		malloc_tab(char *path)
{
	struct dirent	*readir;
	DIR				*dir;
	int				count;

	count = 0;
	dir = opendir(path);
	if (dir == NULL)
		return (1);
	readir = readdir(dir);
	while (readir)
	{
		count++;
		readir = readdir(dir);
	}
	closedir(dir);
	return (count);
}

char	*option_f(t_datafile *fileinfo)
{
	if (fileinfo->filenumber == 3)
		return ("/");
	if (fileinfo->mode[0] == '-' && fileinfo->mode[9] == 'x')
		return ("*");
	if (fileinfo->filenumber == 1)
		return ("@");
	if (fileinfo->filenumber == 5)
		return ("|");
	else
		return ("");
}

char	*handle_filename(char *path, t_datafile *fileinfo)
{
	char	*str;
	char	*tmp;

	str = ft_strrchr(path, '/');
	if (str == NULL)
		return (ft_strdup(path));
	if (g_flag_int.opt[5] == 1)
	{
		tmp = ft_strjoin(&str[1], option_f(fileinfo));
		return (tmp);
	}
	return (ft_strdup(&str[1]));
}

int		print_error_options(char c)
{
	printf("ls: illegal option -- %c\nusage: ls [-FRUaflrst] [file ...]\n", c);
	return (0);
}

char	*handle_links(char *path)
{
	char	buf[1024];
	size_t	result;
	int		len;

	ft_memset(buf, 0, sizeof(buf));
	result = readlink(path, buf, sizeof(buf));
	len = ft_strlen(buf);
	return (ft_strdup(buf));
}
