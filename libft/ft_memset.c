/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 10:17:14 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/11 15:01:04 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			l;
	unsigned char	*d;

	d = (unsigned char*)b;
	l = 0;
	while (l < len)
		d[l++] = (unsigned char)c;
	return (b);
}
