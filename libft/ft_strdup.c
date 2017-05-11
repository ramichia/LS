/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:15:53 by ramichia          #+#    #+#             */
/*   Updated: 2017/01/25 18:20:40 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		length;
	int		i;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (length + 1));
	if (str != NULL)
	{
		i = 0;
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
