/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:05:03 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:05:04 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list *)malloc(sizeof(t_list))))
	{
		if (content != 0)
		{
			if (!(list->content = ft_memalloc(content_size + 1)))
				return (NULL);
			ft_strncpy(list->content, (void *)content, content_size);
			list->content_size = content_size;
		}
		else
		{
			list->content = 0;
			list->content_size = 0;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
