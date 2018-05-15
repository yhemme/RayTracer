/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:59:36 by yhemme            #+#    #+#             */
/*   Updated: 2017/04/18 19:02:38 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*head;
	t_list	*new;

	head = ft_lstnew(lst->content, lst->content_size);
	while (lst->next != NULL)
	{
		lst = lst->next;
		new = ft_lstnew(lst->content, lst->content_size);
		ft_lstaddend(head, new);
	}
	return (head);
}
