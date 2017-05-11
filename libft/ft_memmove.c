/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:47:17 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/15 19:06:55 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)malloc((n * sizeof(unsigned char)));
	if (tmp == NULL)
		return (dest);
	s2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = s2[i];
		i++;
	}
	s1 = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		s1[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (dest);
}
