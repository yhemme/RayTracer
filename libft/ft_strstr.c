/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:28:33 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/13 23:08:19 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	j = 0;
	i = 0;
	if (!*little)
		return ((char*)big);
	while (big[i])
	{
		if (big[i] != little[j])
		{
			j = 0;
			i++;
		}
		else
		{
			tmp = i;
			while (big[i] == little[j] && big[i++] && little[j++])
				if (j == ft_strlen(little))
					return ((char*)&big[i - j]);
			i = tmp + 1;
		}
	}
	return (NULL);
}
