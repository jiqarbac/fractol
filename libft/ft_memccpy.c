/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:05:17 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:05:18 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			k;
	const char		*s;
	char			*d;
	size_t			l;

	k = (char)c;
	s = (const char *)src;
	d = (char *)dst;
	l = 0;
	while (l < n)
	{
		d[l] = s[l];
		if (s[l] == k)
			return (dst + l + 1);
		l++;
	}
	return (NULL);
}
