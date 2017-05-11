/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:42:23 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/11 12:48:12 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	colors_no_options(t_datafile fileinfo, int i)
{
	if (fileinfo.mode[0] == '-' && fileinfo.mode[9] == 'x')
		ft_printf("\033[31m%s\033[0m\n", fileinfo.filename);
	else if (fileinfo.mode[0] == 'd')
	{
		while (i < 10 && fileinfo.mode[i] != '-')
			i++;
		if (fileinfo.mode[9] == 't' || fileinfo.mode[9] == 'T')
			ft_printf("\033[42m\033[30m%s\033[0m\n", fileinfo.filename);
		else if (i == 10)
			ft_printf("\033[43m\033[30m%s\033[0m\n", fileinfo.filename);
		else
			ft_printf("\033[96m%s\033[0m\n", fileinfo.filename);
	}
	else if (fileinfo.mode[0] == 'l')
		ft_printf("\033[35m%s\033[0m\n", fileinfo.filename);
	else if (fileinfo.mode[0] == 'c')
		ft_printf("\033[43m\033[34m%s\033[0m\n", fileinfo.filename);
	else if (fileinfo.mode[0] == 'b')
		ft_printf("\033[46m\033[34m%s\033[0m\n", fileinfo.filename);
	else if (fileinfo.mode[0] == 'p')
		ft_printf("\033[33m%s\033[0m\n", fileinfo.filename);
	else if (fileinfo.mode[0] == 's')
		ft_printf("\033[32m%s\033[0m\n", fileinfo.filename);
	else
		ft_printf("%s\n", fileinfo.filename);
}
