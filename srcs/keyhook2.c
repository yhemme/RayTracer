/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:40:51 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/09 17:11:03 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	moveset(int key, t_env *e)
{
	if (key == UP)
		e->key.up = 1;
	if (key == DOWN)
		e->key.down = 1;
	if (key == LEFT)
		e->key.left = 1;
	if (key == RIGHT)
		e->key.right = 1;
	if (key == W)
		e->key.w = 1;
	if (key == S)
		e->key.s = 1;
	if (key == A)
		e->key.a = 1;
	if (key == D)
		e->key.d = 1;
	if (key == 53)
		exit(0);
}

void	filter_keys(int key, t_env *e)
{
	key == 83 ? e->key.bw++ : 0;
	key == 84 ? e->key.sepia++ : 0;
	key == 85 ? e->key.cartoon++ : 0;
	key == 88 ? e->key.chess++ : 0;
	key == 89 ? e->key.rainbow++ : 0;
	key == 91 ? e->key.wave++ : 0;
	if (key == 35)
	{
		ft_bzero(e->img, (HEIGHT * WIDTH) * 4);
		e->key.pix++;
	}
	if (key == 12)
	{
		ft_bzero(e->img, (HEIGHT * WIDTH) * 4);
		e->key.msaa++;
	}
}

void	key_filters(int key, t_env *e)
{
	t_obj	*lst;

	lst = e->obj;
	filter_keys(key, e);
	if (key == 86)
	{
		ft_bzero(e->img, (HEIGHT * WIDTH) * 4);
		e->key.blur++;
	}
	if (key == 87)
	{
		while (lst)
		{
			if (lst->transp && lst->type == PLAN)
				break ;
			lst = lst->next;
		}
		if (lst)
			lst->transp ? 0 : e->key.sin++;
		else
			e->key.sin++;
	}
}
