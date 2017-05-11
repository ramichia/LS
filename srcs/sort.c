/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:56:39 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:43 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_issort(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void	sort_ascii(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
		}
		i++;
		if (!tab[i + 1] && !ft_issort(tab))
			i = 0;
	}
}

int		ft_issort_struct(t_datafile *tab)
{
	int		i;

	i = 0;
	while (tab[i].filename)
	{
		if (tab[i + 1].filename != NULL && ft_strcmp(tab[i].filename, \
			tab[i + 1].filename) > 0)
			return (0);
		i++;
	}
	return (1);
}

void	sort_tab_ascii(t_datafile *tab)
{
	int			i;
	t_datafile	tmp;

	i = 0;
	while (tab[i].filename)
	{
		if (tab[i + 1].filename && ft_strcmp(tab[i].filename, \
			tab[i + 1].filename) > 0)
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
		}
		i++;
		if (!tab[i + 1].filename && !ft_issort_struct(tab))
			i = 0;
	}
}

int		ft_issort_struct_rev(t_datafile *tab)
{
	int		i;

	i = 0;
	while (tab[i].filename)
	{
		if (tab[i + 1].filename != NULL && ft_strcmp(tab[i].filename, \
			tab[i + 1].filename) < 0)
			return (0);
		i++;
	}
	return (1);
}
