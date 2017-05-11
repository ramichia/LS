/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 02:25:52 by ramichia          #+#    #+#             */
/*   Updated: 2017/02/21 00:13:22 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_puissance(int n)
{
	int		i;
	int		puissance;

	i = 0;
	puissance = 1;
	while (i < n - 1)
	{
		puissance = puissance * 10;
		i++;
	}
	return (puissance);
}

static int		ft_count(unsigned long n)
{
	int		count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	unsigned long	nbis;
	int				i;
	int				power;
	char			*str;

	nbis = (n < 0) ? -(unsigned long)n : (unsigned long)n;
	i = 0;
	power = ft_puissance(ft_count(nbis));
	str = (char*)malloc(sizeof(char) * (ft_count(nbis) + 2));
	if (str != NULL)
	{
		if (n < 0)
		{
			str[i] = '-';
			i++;
		}
		while (power > 0)
		{
			str[i++] = '0' + ((nbis / power) % 10);
			power = power / 10;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
