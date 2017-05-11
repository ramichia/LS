/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:58:17 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:54:27 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	convert_hexa(int nbr)
{
	char	c;

	if (nbr == 10)
		return (c = 'A');
	else if (nbr == 11)
		return (c = 'B');
	else if (nbr == 12)
		return (c = 'C');
	else if (nbr == 13)
		return (c = 'D');
	else if (nbr == 14)
		return (c = 'E');
	else if (nbr == 15)
		return (c = 'F');
	else
		return (c = '0' + nbr);
}

char	convert_hexa2(int nbr)
{
	char	c;

	if (nbr == 10)
		return (c = 'a');
	else if (nbr == 11)
		return (c = 'b');
	else if (nbr == 12)
		return (c = 'c');
	else if (nbr == 13)
		return (c = 'd');
	else if (nbr == 14)
		return (c = 'e');
	else if (nbr == 15)
		return (c = 'f');
	else
		return (c = '0' + nbr);
}

int		malloc_size(uintmax_t nbr, int base)
{
	int		count;

	count = 1;
	while (0 < nbr)
	{
		nbr = nbr / base;
		count++;
	}
	return (count);
}

void	convert_base(uintmax_t nbr, int base)
{
	int		size;
	int		modulo;
	int		i;

	if (nbr == 0)
		g_data.to_display[0] = '0';
	else
	{
		size = malloc_size(nbr, base);
		free(g_data.to_display);
		g_data.to_display = ft_strnew(size);
		i = size - 2;
		while (0 < nbr)
		{
			modulo = nbr % base;
			g_data.to_display[i] = convert_hexa(modulo);
			nbr = nbr / base;
			i--;
		}
		g_data.to_display[size] = '\0';
	}
}

void	convert_base2(uintmax_t nbr, int base)
{
	int		size;
	int		modulo;
	int		i;

	if (nbr == 0)
		g_data.to_display[0] = '0';
	else
	{
		size = malloc_size(nbr, base);
		free(g_data.to_display);
		g_data.to_display = ft_strnew(size);
		i = size - 2;
		while (0 < nbr)
		{
			modulo = nbr % base;
			g_data.to_display[i] = convert_hexa2(modulo);
			nbr = nbr / base;
			i--;
		}
		g_data.to_display[size] = '\0';
	}
}
