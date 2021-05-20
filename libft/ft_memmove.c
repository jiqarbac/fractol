/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:05:47 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:05:48 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d1;

	if (src < dst)
	{
		if ((d1 = (char *)malloc(sizeof(char) * (len))))
		{
			ft_memcpy((void *)d1, src, len);
			ft_memcpy(dst, (void *)d1, len);
			free(d1);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
