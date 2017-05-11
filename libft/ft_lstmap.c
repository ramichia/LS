/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:56:15 by ramichia          #+#    #+#             */
/*   Updated: 2016/12/08 16:29:07 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;

	if (!lst)
		return (NULL);
	newlist = NULL;
	if (lst)
	{
		newlist = (*f)(lst);
		if (lst->next)
			newlist->next = ft_lstmap(lst->next, f);
	}
	return (newlist);
}
