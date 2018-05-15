/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chess.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:33:34 by yhemme            #+#    #+#             */
/*   Updated: 2018/05/15 14:55:50 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	define_chess_values(t_env *e, t_obj *obj)
{
	e->chess.p = vector_sub(vector_add(obj->inter,
				vector_mult(obj->n, 0.001)), obj->pos);
	e->chess.x1 = (int)(floor((e->chess.p.x / 2)));
	e->chess.y1 = (int)(floor((e->chess.p.y / 2)));
	e->chess.z1 = (int)(floor((e->chess.p.z / 2)));
}

void	first_choice(t_env *e, t_obj *obj)
{
	if ((e->chess.x1 % 2 == 0 && e->chess.y1 % 2 == 0) ||
			(e->chess.x1 % 2 != 0 && e->chess.y1 % 2 != 0))
	{
		obj->color.red = 1;
		obj->color.green = 1;
		obj->color.blue = 1;
	}
	else
	{
		obj->color.red = 0;
		obj->color.green = 0;
		obj->color.blue = 0;
	}
}

void	second_choice(t_env *e, t_obj *obj)
{
	if ((e->chess.x1 % 2 == 0 && e->chess.y1 % 2 == 0) ||
			(e->chess.x1 % 2 != 0 && e->chess.y1 % 2 != 0))
	{
		obj->color.red = 0;
		obj->color.green = 0;
		obj->color.blue = 0;
	}
	else
	{
		obj->color.red = 1;
		obj->color.green = 1;
		obj->color.blue = 1;
	}
}

void	chess(t_env *e, t_obj *obj)
{
	define_chess_values(e, obj);
	if (e->chess.z1 % 2 == 0)
		first_choice(e, obj);
	else
		second_choice(e, obj);
}
