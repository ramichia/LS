/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:04:55 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/16 18:49:47 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] || s2[i])
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
	}
	return (1);
}
