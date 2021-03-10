/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:08:12 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:08:13 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revtab(char *tab)
{
	char	*rvtb;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (tab)
	{
		i = ft_strlen(tab) - 1;
		if ((rvtb = malloc(ft_strlen(tab) + 1)))
		{
			while (tab[j])
				rvtb[j++] = tab[i--];
			rvtb[j] = '\0';
		}
		return (rvtb);
	}
	return (NULL);
}
