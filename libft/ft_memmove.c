/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:05:40 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/18 18:05:35 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (len == 0)
		return (dst);
	if (dst <= src)
	{
		while (++i < len)
			*d++ = *s++;
	}
	if (dst > src)
	{
		len--;
		while (len > 0)
		{
			d[len] = s[len];
			len--;
		}
	}
	d[0] = s[0];
	return (dst);
}
