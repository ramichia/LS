/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:34:15 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/17 12:32:14 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(sizeof(char) * (len + 1));
	if (s != NULL)
	{
		if (str != NULL)
		{
			i = 0;
			while (i < len)
			{
				str[i] = s[start];
				i++;
				start++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	else
		return (NULL);
}
