/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 02:30:55 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/17 12:29:16 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	d;

	i = 0;
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	d = (unsigned char)c;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == d)
		{
			s1[i] = s2[i];
			return ((void*)s1 + i + 1);
		}
		i++;
	}
	return (NULL);
}
