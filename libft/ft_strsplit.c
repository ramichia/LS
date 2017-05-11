/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:29:36 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/16 21:23:01 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static void		createline(char const *s, char **str, char c, size_t i)
{
	int		k;
	int		j;

	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] != c)
		{
			str[j][k] = s[i];
			i++;
			k++;
		}
		str[j][k] = '\0';
		j++;
		while (s[i] == c)
			i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_countwords(s, c);
	str = (char**)malloc(sizeof(char*) * (ft_countwords(s, c) + 1));
	if (str != NULL)
	{
		while (i < j)
		{
			str[i] = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
			i++;
		}
		i = 0;
		createline(s, str, c, i);
		str[j] = 0;
		return (str);
	}
	return (NULL);
}
