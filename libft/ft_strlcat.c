/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:15:34 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/13 18:18:57 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		lendst;
	size_t		lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	n = size == 0 ? 1 : size - ft_strlen(dst);
	if (lendst >= size)
		return (ft_strlen(src) + size);
	while (*dst != '\0')
		dst++;
	while (*src != '\0')
	{
		if (n != 1 && n--)
			*dst++ = *src;
		src++;
	}
	*dst = '\0';
	if (size == 0)
		return (lensrc);
	return (lendst + lensrc);
}
