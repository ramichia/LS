/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 23:47:09 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/02 23:48:01 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list *alst, t_list *new)
{
	t_list	*tmp;

	tmp = alst;
	alst->start = alst;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
	new->start = tmp;
}
