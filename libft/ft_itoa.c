/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:37:41 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/19 17:24:37 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size(int n)
{
	size_t			i;
	unsigned int	j;

	i = 0;
	if (n < 0)
	{
		i++;
		j = (size_t)-n;
	}
	else
		j = (size_t)n;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*s;
	size_t	j;
	size_t	i;

	i = size(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(s = (char*)malloc(sizeof(char) * size(n) + 1)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		j = (size_t)-n;
	}
	else
		j = (size_t)n;
	while (j > 0)
	{
		s[i--] = (j % 10) + '0';
		j = j / 10;
	}
	s[size(n)] = '\0';
	return (s);
}
