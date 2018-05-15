/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 21:22:17 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/14 21:36:54 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (!(s = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
