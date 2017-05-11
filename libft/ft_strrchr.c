/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:57:24 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/17 12:32:03 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	to_find;

	length = ft_strlen(s);
	to_find = (char)c;
	while (length >= 0 && s[length] != to_find)
		length--;
	if (s[length] == to_find)
		return ((char*)&s[length]);
	else
		return (NULL);
}
