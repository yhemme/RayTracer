/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:51:11 by yhemme            #+#    #+#             */
/*   Updated: 2018/04/03 14:22:09 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_letters(char const *string, char divider)
{
	int i;

	i = 0;
	while (string[i] && string[i] != divider)
		i++;
	return (i);
}

static int		ft_c_w(char const *string, char divider)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (string[i])
	{
		while (string[i] == divider && string[i])
			i++;
		if (string[i])
			counter++;
		while (string[i] != divider && string[i])
			i++;
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;
	char	**ret;

	i = 0;
	j = 0;
	if (!s || !c || !(ret = (char **)malloc(sizeof(ret) * (ft_c_w(s, c) + 1))))
		return (NULL);
	while (s[i] && (int)j < ft_c_w(s, c))
	{
		while (s[i] == c)
			i++;
		k = 0;
		len = ft_count_letters(s + i, c);
		if (!(ret[j] = (char *)malloc(sizeof(*ret) * (len + 1))))
			return (NULL);
		while (k < len)
			ret[j][k++] = s[i++];
		ret[j++][k] = '\0';
	}
	ret[j] = 0;
	return (ret);
}
