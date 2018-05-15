/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:15:48 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/13 21:25:07 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char*)&s[ft_strlen(s)]);
	if (!*s)
		return (NULL);
	while (*s)
		s++;
	s--;
	while (i > 0)
	{
		if (*s == (char)c)
			return ((char*)s);
		s--;
		i--;
	}
	return (NULL);
}
