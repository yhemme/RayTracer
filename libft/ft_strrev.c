/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:28:57 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/19 16:21:25 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	c;

	if (!s)
		return (NULL);
	j = 0;
	i = ft_strlen(s) - 1;
	while (j < i)
	{
		c = s[j];
		s[j] = s[i];
		s[i] = c;
		j++;
		i--;
	}
	return (s);
}
