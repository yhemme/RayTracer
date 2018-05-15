/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:55:38 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/19 17:01:14 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new;
	t_list	*current;

	first = NULL;
	while (lst)
	{
		new = f(lst);
		if (!first)
		{
			first = new;
			current = first;
		}
		else
		{
			current->next = new;
			current = current->next;
		}
		lst = lst->next;
	}
	return (first);
}
