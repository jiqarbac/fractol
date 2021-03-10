/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:12:28 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:12:29 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	if (s != NULL)
	{
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (j > i))
			j--;
		if ((str = (char *)malloc(sizeof(char) * (j - i + 2))))
		{
			while (i <= j && s[i])
				str[l++] = s[i++];
			str[l] = '\0';
			return (str);
		}
		return (NULL);
	}
	return (NULL);
}
