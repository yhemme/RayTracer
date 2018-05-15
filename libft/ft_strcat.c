/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:16:34 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/13 10:24:16 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	static int	len;
	int			j;

	j = 0;
	len = ft_strlen(s1);
	while (s2[j] != '\0')
	{
		s1[len] = s2[j];
		len++;
		j++;
	}
	s1[len] = '\0';
	return (s1);
}