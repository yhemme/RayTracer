/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:26:29 by yhemme            #+#    #+#             */
/*   Updated: 2017/09/11 11:44:50 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && len)
	{
		dst[i] = src[i];
		len--;
		i++;
	}
	while (len)
	{
		dst[i] = '\0';
		len--;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
