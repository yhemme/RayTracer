/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:34:36 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/14 10:42:37 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	j = 0;
	i = 0;
	if (!*little)
		return ((char*)big);
	while (big[i] && i < len)
	{
		if (big[i] != little[j])
		{
			j = 0;
			i++;
		}
		else
		{
			tmp = i;
			while (i < len && big[i] == little[j] && big[i++] && little[j++])
				if (j == ft_strlen(little))
					return ((char*)&big[i - j]);
			i = tmp + 1;
		}
	}
	return (NULL);
}
