/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:14:20 by yhemme            #+#    #+#             */
/*   Updated: 2018/04/19 18:08:46 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	move(t_env *e)
{
	t_vec3	forward;
	t_vec3	right;

	forward_vec_create(&forward);
	rotation_apply(e, &forward);
	right_vec_create(&right);
	rotation_apply(e, &right);
	if (e->key.w == 1)
		e->cam->pos = vector_sub(e->cam->pos, forward);
	if (e->key.a == 1)
		e->cam->pos = vector_sub(e->cam->pos, right);
	if (e->key.d == 1)
		e->cam->pos = vector_add(e->cam->pos, right);
	if (e->key.s == 1)
		e->cam->pos = vector_add(e->cam->pos, forward);
}

void	rotate(t_env *e)
{
	if (e->key.up == 1)
		angle_increase(e, 3, 0);
	if (e->key.down == 1)
		angle_increase(e, -3, 0);
	if (e->key.right == 1)
		angle_increase(e, 0, -3);
	if (e->key.left == 1)
		angle_increase(e, 0, 3);
}

int		key_release(int key, t_env *e)
{
	if (key == UP)
		e->key.up = 0;
	if (key == DOWN)
		e->key.down = 0;
	if (key == LEFT)
		e->key.left = 0;
	if (key == RIGHT)
		e->key.right = 0;
	if (key == W)
		e->key.w = 0;
	if (key == S)
		e->key.s = 0;
	if (key == A)
		e->key.a = 0;
	if (key == D)
		e->key.d = 0;
	return (1);
}

int		key_press(int key, t_env *e)
{
	moveset(key, e);
	if (key == 69 && e->amb < 1)
		e->amb += 0.1;
	if (key == 78 && e->amb > 0)
		e->amb -= 0.1;
	key_filters(key, e);
	e->key.move_tex.x += key == 4 ? 0.2 : 0;
	e->key.move_tex.x -= key == 40 ? 0.2 : 0;
	e->key.move_tex.z -= key == 32 ? 0.2 : 0;
	e->key.move_tex.z += key == 38 ? 0.2 : 0;
	e->key.stretch.x += key == 16 ? 2 : 0;
	e->key.stretch.x -= key == 34 && e->key.stretch.x > 0 ? 2 : 0;
	key == 46 ? e->key.repeat++ : 0;
	if (key == 106)
		screenshot(e);
	if (key == 15)
		readobject(e);
	return (1);
}
