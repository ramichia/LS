/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 23:56:01 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:40 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		count_links_size(t_datafile *tab)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	count = 0;
	while (tab[i].filename)
	{
		tmp = ft_itoa(tab[i].nb_links);
		if (count < (int)ft_strlen(tmp))
			count = (int)ft_strlen(tmp);
		i++;
		ft_strdel(&tmp);
	}
	return (count + 1);
}

int		count_file_size(t_datafile *tab)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	count = 0;
	while (tab[i].filename)
	{
		tmp = ft_itoa(tab[i].size);
		if (count < (int)ft_strlen(tmp))
			count = (int)ft_strlen(tmp);
		i++;
		ft_strdel(&tmp);
	}
	return (count);
}

int		count_username_size(t_datafile *tab)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tab[i].filename)
	{
		if (count < (int)ft_strlen(tab[i].username))
			count = (int)ft_strlen(tab[i].username);
		i++;
	}
	return (count);
}

int		count_block_size(t_datafile *tab)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	count = 0;
	while (tab[i].filename)
	{
		tmp = ft_itoa(tab[i].nb_blocks);
		if (count < (int)ft_strlen(tmp))
			count = (int)ft_strlen(tmp);
		i++;
		ft_strdel(&tmp);
	}
	return (count);
}
