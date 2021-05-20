/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:04:11 by jiqarbac          #+#    #+#             */
/*   Updated: 2021/03/10 12:04:12 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa2(int n, char *str, int i)
{
	char	j;

	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		while (--i > 1)
		{
			j = (n % 10) + 48;
			n /= 10;
			if (i != 0 && i != 1)
				str[i] = j;
		}
	}
	return (str);
}

static char		*ft_itoa3(int n, char *str, int i, int k)
{
	char	j;

	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (--i > k)
	{
		j = (n % 10) + 48;
		n /= 10;
		str[i] = j;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		k;
	char	*str;

	k = 0;
	i = ft_compt_digit(n);
	if ((str = (char *)malloc(i + 1)))
	{
		str[i] = '\0';
		if (n >= 0)
			k = -1;
		if (n == -2147483648)
			ft_itoa2(n, str, i);
		else
			ft_itoa3(n, str, i, k);
		return (str);
	}
	return (NULL);
}
