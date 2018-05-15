/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:01:17 by yhemme            #+#    #+#             */
/*   Updated: 2017/09/11 17:26:18 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char *str, char c)
{
	int	nb;
	int	new;

	nb = 0;
	new = 1;
	if (*str)
	{
		while (*str)
		{
			if (*str == c)
				new = 1;
			else if (new)
			{
				new = 0;
				nb++;
			}
			str++;
		}
		return (nb);
	}
	return (-1);
}
