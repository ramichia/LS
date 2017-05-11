/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:26:04 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:33 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_datafile	*ls(char *path)
{
	if (g_flag_int.opt[1] == 1)
		return (fill_table_rec(path, 0));
	else
		return (fill_table(path));
}

void		handle_char_tab(char **tab)
{
	int			i;
	t_datafile	*tabus;

	i = 0;
	if (g_flag_int.opt[3] == 1 || g_flag_int.opt[2] == 1)
	{
		stock_files_l(tab);
		return ;
	}
	while (tab[i])
	{
		tabus = fill_table_file(tab[i]);
		free_tab(tabus);
		i++;
	}
}

void		handle_char_tab_dir(char **tab)
{
	int			i;
	t_datafile	*tabus;

	i = 0;
	while (tab[i])
	{
		if (i != 0)
			ft_printf("\n%s:\n", tab[i]);
		tabus = ls(tab[i]);
		free_tab(tabus);
		i++;
	}
	free_char_tab(tab);
}

int			main(int argc, char **argv)
{
	char		**tab;
	char		**tab2;

	tab = NULL;
	tab2 = NULL;
	if (argv[1] && handle_options(argv) == 0)
		return (0);
	print_error(argc, argv);
	if (1 <= argc)
	{
		tab = get_arg_file(argc, argv);
		tab2 = sort_dir(get_arg_dir(argc, argv));
	}
	errno = 0;
	handle_char_tab(tab);
	if (tab2[0] != NULL && tab[0] != NULL)
		ft_printf("\n");
	if (tab2[0] != NULL && tab[0] != NULL)
		ft_printf("%s:\n", tab2[0]);
	else if (tab2[0] != NULL && tab2[1] != NULL)
		ft_printf("%s:\n", tab2[0]);
	free_char_tab(tab);
	errno = 0;
	handle_char_tab_dir(tab2);
	return (0);
}
