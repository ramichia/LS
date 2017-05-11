/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:00:18 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/15 11:27:41 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)malloc(sizeof(char) * size);
	if (tmp == NULL)
		return (NULL);
	else
		return (ft_memset(tmp, 0, size));
}
