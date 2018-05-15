/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:23:38 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/19 17:25:42 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*d;
	size_t	len;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	len = ft_strlen(s);
	len2 = ft_strlen(s) - 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	while ((s[len2] == ' ' || s[len2] == '\t' || s[len2] == '\n') && len2 != 0)
		len2--;
	if (len2 == 0)
		return (ft_strdup(""));
	if (!(d = (char *)malloc(sizeof(char) * len2 - i + 2)))
		return (NULL);
	while (i < len2 + 1 && i != len)
		d[j++] = s[i++];
	d[j] = '\0';
	return (d);
}
