/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:26:34 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:24 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		initiate_gflagint(void)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		g_flag_int.opt[i] = 0;
		i++;
	}
	return (1);
}

int		cmp_optionflag(char c)
{
	int		i;

	i = 0;
	while (i < 9 && g_optionflags[i] != c)
		i++;
	if (i == 9)
		return (9);
	g_flag_int.opt[i] = 1;
	return (i);
}

int		handle_options(char **argv)
{
	int		i;
	int		j;

	i = initiate_gflagint();
	if (!argv[i])
		return (1);
	while (argv[i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (cmp_optionflag(argv[i][j]) == 9)
				return (print_error_options(argv[i][j]));
			j++;
		}
		if (j == 1)
			return (-1);
		i++;
	}
	if (g_flag_int.opt[7] == 1)
	{
		g_flag_int.opt[4] = 1;
		g_flag_int.opt[6] = 1;
	}
	return (i);
}

char	**no_arg(char **args)
{
	args[0] = ft_strdup(".");
	args[1] = NULL;
	return (args);
}

char	**get_arg_file(int argc, char **argv)
{
	char			**args;
	int				i;
	int				j;
	struct stat		buf;
	int				r;

	i = 1;
	if (!(args = (char**)malloc(sizeof(char*) * (argc - no_file(argv)))))
		return (NULL);
	while (i < argc && argv[i][0] == '-')
		i++;
	j = 0;
	if (!argv[i])
		return (no_arg_2(args));
	while (argv[i])
	{
		r = lstat(argv[i], &buf);
		if (r != -1 && !S_ISDIR(buf.st_mode))
			args[j++] = ft_strdup(argv[i]);
		i++;
	}
	args[j] = NULL;
	if (j != 0)
		sort_ascii(args);
	return (args);
}
