/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_modificateur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:55:36 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:55:02 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		match_length(char c)
{
	int		i;

	i = 0;
	while (g_flags_length[i] && g_flags_length[i] != c)
		i++;
	return (i);
}

char	find_length2(int count, int i, char *str)
{
	if (count == 0)
		return ('N');
	if (count == 1)
		return (str[i - 2]);
	else
		return (g_flags_length[match_length(str[i - 2]) + 4]);
}

char	match_l(char *str, int i)
{
	if ((match_length(str[i + 1]) == 0))
		return ('L');
	else
		return ('l');
}

char	match_h(char *str, int i)
{
	if ((match_length(str[i + 1]) == 1))
		return ('H');
	else
		return ('h');
}

char	find_length(char *str, int i)
{
	if (g_data.conv == 4 || g_data.conv == 7)
		return ('l');
	while (str[i])
	{
		if (match_length(str[i]) < 4)
		{
			if (match_length(str[i]) == 2)
				return ('j');
			if (match_length(str[i]) == 3)
				return ('z');
			if (match_length(str[i]) == 0)
				return (match_l(str, i));
			if (match_length(str[i]) == 1)
			{
				if ((match_length(str[i + 1]) == 1))
				{
					if (match_length(str[i + 2]) < 4)
						i = i + 2;
				}
				return (match_h(str, i));
			}
		}
		i++;
	}
	return ('N');
}
