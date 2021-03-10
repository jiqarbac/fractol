/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:04:57 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:04:58 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst1;
	t_list	*tmp;

	if (lst)
	{
		lst1 = f(lst);
		lst = lst->next;
		tmp = lst1;
		while (lst)
		{
			lst1->next = f(lst);
			lst1 = lst1->next;
			lst = lst->next;
		}
		lst1->next = NULL;
		return (tmp);
	}
	return (NULL);
}
