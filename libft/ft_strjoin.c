/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:47:06 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/19 16:44:50 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	ld;

	if (!s1 || !s2)
		return (NULL);
	ld = 0;
	d = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
		return (NULL);
	while (*s1)
	{
		d[ld++] = *s1;
		s1++;
	}
	while (*s2)
	{
		d[ld++] = *s2;
		s2++;
	}
	d[ld] = '\0';
	return (d);
}
