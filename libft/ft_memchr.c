/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:05:24 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:05:25 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	t;
	size_t	i;

	i = 0;
	str = (char *)s;
	t = (char)c;
	while (i < n)
	{
		if (str[i] == t)
			return (str + i);
		i++;
	}
	return (NULL);
}
