/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:04:48 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:04:49 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*lstnw;

	if (lst)
	{
		lstnw = lst;
		while (lstnw)
		{
			f(lstnw);
			lstnw = lstnw->next;
		}
	}
}
