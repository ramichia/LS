/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:13:45 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 18:54:41 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	handle_sign(intmax_t nbr)
{
	if (nbr < 0)
	{
		free(g_data.sign);
		g_data.sign = ft_strdup("-");
		nbr = -nbr;
	}
	return ((uintmax_t)nbr);
}

void		cast1(va_list *arg)
{
	intmax_t	nbr;

	if (g_data.length == 'z')
		nbr = (uintmax_t)va_arg(*arg, size_t);
	else if (g_data.length == 'j')
		nbr = va_arg(*arg, uintmax_t);
	else if (g_data.length == 'H')
		nbr = (uintmax_t)(unsigned char)va_arg(*arg, unsigned int);
	else if (g_data.length == 'h')
		nbr = (uintmax_t)(unsigned short)va_arg(*arg, unsigned int);
	else if (g_data.length == 'l')
		nbr = (uintmax_t)va_arg(*arg, unsigned long);
	else if (g_data.length == 'L')
		nbr = (uintmax_t)va_arg(*arg, unsigned long long);
	else
		nbr = (uintmax_t)va_arg(*arg, unsigned int);
	g_data.nbr = nbr;
	convert_int(nbr);
}

void		cast2(va_list *arg)
{
	intmax_t	nbr;
	uintmax_t	nbr2;

	if (g_data.length == 'z')
		nbr = (intmax_t)va_arg(*arg, size_t);
	else if (g_data.length == 'j')
		nbr = va_arg(*arg, intmax_t);
	else if (g_data.length == 'H')
		nbr = (intmax_t)(char)va_arg(*arg, int);
	else if (g_data.length == 'h')
		nbr = (intmax_t)(short)va_arg(*arg, int);
	else if (g_data.length == 'l')
		nbr = (intmax_t)va_arg(*arg, long);
	else if (g_data.length == 'L')
		nbr = (intmax_t)va_arg(*arg, long long);
	else
		nbr = (intmax_t)va_arg(*arg, int);
	nbr2 = handle_sign(nbr);
	convert_int(nbr2);
}

void		cast3(va_list *arg)
{
	intmax_t	nbr;

	if (g_data.length == 'z')
		nbr = (uintmax_t)va_arg(*arg, size_t);
	else if (g_data.length == 'j')
		nbr = va_arg(*arg, uintmax_t);
	else if (g_data.length == 'H')
		nbr = (uintmax_t)va_arg(*arg, unsigned int);
	else if (g_data.length == 'h')
		nbr = (uintmax_t)va_arg(*arg, unsigned int);
	else if (g_data.length == 'l')
		nbr = (uintmax_t)va_arg(*arg, unsigned long);
	else if (g_data.length == 'L')
		nbr = (uintmax_t)va_arg(*arg, unsigned long long);
	else
		nbr = (uintmax_t)va_arg(*arg, unsigned long);
	convert_int(nbr);
}

void		cast_nbr(va_list *arg)
{
	if (g_data.conv == 6 || g_data.conv == 8 || g_data.conv == 10 \
		|| g_data.conv == 11)
		cast1(arg);
	else if (g_data.conv == 7 || g_data.conv == 9)
		cast3(arg);
	else
		cast2(arg);
}
