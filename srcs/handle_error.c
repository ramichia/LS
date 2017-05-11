/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 20:35:07 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:30 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		no_file(char **argv)
{
	int				i;
	int				returnvalue;
	DIR				*dir;
	struct stat		buf;
	int				count;

	i = handle_options(argv);
	count = 0;
	while (argv[i])
	{
		dir = opendir(argv[i]);
		returnvalue = stat(argv[i], &buf);
		if (dir == NULL && returnvalue == -1)
			count++;
		i++;
		if (dir != NULL)
			closedir(dir);
	}
	return (count);
}

int		print_error_bis(char **errormessage)
{
	int		i;
	char	*errortext;

	i = 0;
	while (errormessage[i])
	{
		errortext = strerror(errno);
		ft_printf("ls: %s: %s\n", errormessage[i], errortext);
		i++;
	}
	return (0);
}

int		print_error_no_file(char **argv)
{
	if (handle_options(argv) == -1)
		ft_printf("ls: -: No such file or directory\n");
	return (1);
}

void	print_error(int argc, char **argv)
{
	char			**errormessage;
	int				i;
	int				j;
	DIR				*dir;
	struct stat		buf;

	if (!(errormessage = (char**)malloc(sizeof(char*) * (no_file(argv) + 1))))
		return ;
	i = print_error_no_file(argv);
	while (i < argc && argv[i][0] == '-')
		i++;
	j = 0;
	while (i < argc)
	{
		dir = opendir(argv[i]);
		if (dir == NULL && lstat(argv[i], &buf) == -1)
			errormessage[j++] = ft_strdup(argv[i]);
		i++;
		if (dir != NULL)
			closedir(dir);
	}
	errormessage[j] = NULL;
	sort_ascii(errormessage);
	print_error_bis(errormessage);
	free_char_tab(errormessage);
}

void	handle_device(dev_t st_rdev, t_datafile *fileinfo)
{
	unsigned int	major;
	unsigned int	minor;

	if (fileinfo->filenumber == 7)
	{
		major = st_rdev;
		while ((major / 256) > 0)
			major = major / 256;
		minor = st_rdev % 256;
		fileinfo->major = major;
		fileinfo->minor = minor;
	}
}
