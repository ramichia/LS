/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:24:27 by ramichia          #+#    #+#             */
/*   Updated: 2017/01/31 00:09:17 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoi(const char *str)
{
	int				i;
	intmax_t		result;
	int				negatif;

	if (!str)
		return (0);
	i = 0;
	result = 0;
	negatif = 0;
	while (str[i] < 47 || 58 < str[i])
		i++;
	if (str[i] == '-')
		negatif = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (negatif == -1)
		result = -result;
	return (result);
}
