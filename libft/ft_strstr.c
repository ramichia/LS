/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:09:44 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/17 12:32:09 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int		i;
	size_t	j;
	size_t	k;

	i = 0;
	k = ft_strlen(aiguille);
	if (k == 0)
		return ((char*)meule_de_foin);
	while (meule_de_foin[i])
	{
		j = 0;
		while (meule_de_foin[i] == aiguille[j])
		{
			i++;
			j++;
			if (j == k)
				return (char*)(&meule_de_foin[i - j]);
		}
		i = i - j + 1;
	}
	return (NULL);
}
