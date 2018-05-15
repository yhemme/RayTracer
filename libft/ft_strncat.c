/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:33:26 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/13 10:37:47 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	static int	len;
	size_t		j;

	j = 0;
	len = ft_strlen(s1);
	while (s2[j] != '\0' && j < n)
	{
		s1[len] = s2[j];
		len++;
		j++;
	}
	s1[len] = '\0';
	return (s1);
}
