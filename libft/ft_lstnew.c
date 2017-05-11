/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:54:44 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/17 00:11:23 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	newlist = (t_list*)malloc(sizeof(t_list));
	if (newlist != NULL)
	{
		if (content == NULL)
		{
			newlist->content = NULL;
			newlist->content_size = 0;
		}
		else
		{
			newlist->content = malloc(content_size);
			if (newlist->content != NULL)
			{
				ft_memcpy(newlist->content, content, content_size);
				newlist->content_size = content_size;
			}
			else
				return (NULL);
		}
		newlist->next = NULL;
		return (newlist);
	}
	return (NULL);
}
