/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:19:24 by ramichia          #+#    #+#             */
/*   Updated: 2017/01/27 13:58:11 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	char	*result;
	int		i;

	count = ft_strlen(str);
	result = (char*)malloc(sizeof(char) * (count + 1));
	count--;
	i = 0;
	while (0 <= count)
	{
		result[i] = str[count];
		i++;
		count--;
	}
	result[i] = '\0';
	return (result);
}
