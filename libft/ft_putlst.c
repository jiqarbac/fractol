/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:07:38 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:07:39 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		if (lst->next != NULL)
			ft_putstr("  --->  ");
		lst = lst->next;
	}
}
