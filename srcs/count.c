/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:55:13 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:15 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		count_s(t_datafile *tab)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tab[i].filename)
	{
		if (ft_strcmp(tab[i].filename, ".") != 0 && \
			ft_strcmp(tab[i].filename, "..") != 0 && tab[i].filename[0] != '.')
			count = count + tab[i].nb_blocks;
		i++;
	}
	return (count);
}

int		count_a(t_datafile *tab)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tab[i].filename)
	{
		count = count + tab[i].nb_blocks;
		i++;
	}
	return (count);
}

int		count(t_datafile *tab)
{
	if (g_flag_int.opt[4] == 1)
		return (count_a(tab));
	else
		return (count_s(tab));
}

void	print_count(t_datafile fileinfo, t_datafile *tab)
{
	int		blocksize;

	blocksize = count_block_size(tab);
	if (g_flag_int.opt[4] == 1)
		ft_printf("%*d ", blocksize, fileinfo.nb_blocks);
	else if (ft_strcmp(fileinfo.filename, ".") != 0 && \
		ft_strcmp(fileinfo.filename, "..") != 0 &&\
		fileinfo.filename[0] != '.')
		ft_printf("%*d ", blocksize, fileinfo.nb_blocks);
}
