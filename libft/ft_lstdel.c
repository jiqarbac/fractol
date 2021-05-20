/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:04:34 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:04:35 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*lstbcl;

	if (*alst)
	{
		lst = *alst;
		while (lst)
		{
			lstbcl = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = lstbcl;
		}
		*alst = NULL;
	}
}
