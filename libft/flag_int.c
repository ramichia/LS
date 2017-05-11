/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:51:45 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:54:53 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		matchf(char c)
{
	int		i;

	i = 0;
	while (g_flags[i] && g_flags[i] != c)
		i++;
	return (i);
}

int		get_int_flag(char *str, int conv, int flag, int i)
{
	while (str[i])
	{
		if (6 < conv && ((matchf(str[i]) == 0 && flag == 3) || \
			(matchf(str[i]) == 3 && flag == 0)))
			flag = 5;
		else if (matchf(str[i]) == 4 || (conv <= 6 && matchf(str[i]) == 3))
			flag = 0 + flag;
		else if (flag == 0 && (matchf(str[i]) == 4 || matchf(str[i]) == 2))
			flag = 0;
		else if (flag == 1 && (matchf(str[i]) == 4 || matchf(str[i] == 2)))
			flag = 1;
		else if (((3 <= conv && conv <= 5) || conv == 12) && \
			matchf(str[i]) == 2 && flag != 1)
			flag = 2;
		else if (flag == 0 && matchf(str[i]) == 1)
			flag = 6;
		else if (5 < conv && matchf(str[i]) == 1 && flag != 0 && flag != 5)
			flag = 0 + flag;
		else if (matchf(str[i]) < 7 && matchf(str[i]) != 4)
			flag = matchf(str[i]);
		i++;
	}
	return (flag);
}
