/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstaddend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 19:56:58 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/18 19:01:48 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list *alst, t_list *new)
{
	t_list	*tmp;

	tmp = alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
