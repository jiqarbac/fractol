/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:11:47 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:11:48 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	x;

	i = 0;
	l = 0;
	if (needle[l] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		l = 0;
		if (needle[l] == haystack[i])
		{
			x = i;
			while (needle[l] == haystack[x] && x < len && needle[l])
			{
				x++;
				l++;
			}
			if (needle[l] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
