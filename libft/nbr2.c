/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:24:30 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:48:59 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	precision_nbr(char *str, int nbr)
{
	char	*tmp;
	int		i;
	int		j;
	char	*tmp2;
	char	*tmp3;

	if (nbr <= 0 && ft_atoi(str) == 0)
		g_data.to_display[0] = '\0';
	else
	{
		tmp = ft_strnew(nbr);
		i = 0;
		while (i < (int)(nbr - ft_strlen(str)))
		{
			tmp[i] = '0';
			i++;
		}
		j = 0;
		tmp2 = tmp;
		tmp3 = ft_strdup(g_data.to_display);
		free(g_data.to_display);
		g_data.to_display = ft_strjoin(tmp, tmp3);
		ft_strdel(&tmp2);
		ft_strdel(&tmp3);
	}
}

void	convert_int(uintmax_t nbr)
{
	if (g_data.conv == 8 || g_data.conv == 9)
		convert_base(nbr, 8);
	else if (g_data.conv == 11)
		convert_base(nbr, 16);
	else if (g_data.conv == 10)
		convert_base2(nbr, 16);
	else
		convert_base(nbr, 10);
}

void	intermediate_hash_key(void)
{
	if ((g_data.conv == 8 || g_data.conv == 9) && g_data.to_display[0] != '0')
	{
		free(g_data.hash_key);
		g_data.hash_key = ft_strdup("0");
	}
	else if (g_data.conv == 11 && g_data.nbr != 0)
	{
		free(g_data.hash_key);
		g_data.hash_key = ft_strdup("0X");
	}
	else if (g_data.conv == 10 && g_data.nbr != 0)
	{
		free(g_data.hash_key);
		g_data.hash_key = ft_strdup("0x");
	}
}

void	flag_hash_key(void)
{
	if (g_data.flag == 3 || g_data.flag == 5)
		intermediate_hash_key();
	if (g_data.flag == 2 && g_data.sign[0] == '+')
	{
		if (3 <= g_data.conv && g_data.conv <= 5)
		{
			free(g_data.hash_key);
			g_data.hash_key = ft_strdup(" ");
		}
	}
}

char	handle_space(void)
{
	if (g_data.flag_zero == 1)
		return ('0');
	else
		return (' ');
}
