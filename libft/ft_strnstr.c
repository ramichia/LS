/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:14:03 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/17 12:31:58 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = ft_strlen(str2);
	if (k == 0)
		return ((char*)str1);
	while (str1[i] && i < len)
	{
		j = 0;
		while (str1[i] == str2[j] && i < len)
		{
			i++;
			j++;
			if (str2[j] == '\0')
				return ((char*)&str1[i - j]);
		}
		i = i - j + 1;
	}
	return (NULL);
}
