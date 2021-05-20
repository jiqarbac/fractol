/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:09:59 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:10:00 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 && s2)
	{
		if ((str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			while (s1[++i])
				str[i] = s1[i];
			while (s2[j])
			{
				str[i] = s2[j];
				i++;
				j++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
