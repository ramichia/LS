/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:04:07 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:27 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**no_arg_2(char **args)
{
	args[0] = NULL;
	return (args);
}

char	**get_arg_dir(int argc, char **argv)
{
	char			**args;
	int				i;
	int				j;
	int				r;
	struct stat		buf;

	i = 1;
	args = (char**)malloc(sizeof(char*) * (argc - no_file(argv)));
	while (i < argc && argv[i][0] == '-')
		i++;
	j = 0;
	if (!argv[i])
		return (no_arg(args));
	while (argv[i])
	{
		r = lstat(argv[i], &buf);
		if (r != -1 && S_ISDIR(buf.st_mode))
			args[j++] = ft_strdup(argv[i]);
		i++;
	}
	args[j] = NULL;
	sort_ascii(args);
	return (args);
}
