/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:19:15 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/19 16:47:53 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_rgb	texture_sphere(t_env *e, t_ray *ray, t_obj *obj)
{
	double	u;
	double	v;
	t_vec3	d;
	t_rgb	col;

	d = vector_sub(obj->pos, obj->inter);
	d = normalize(d);
	u = 0.5 + (atan2(d.z, d.x) / (2.0 * M_PI));
	v = 0.5 - (asin(d.y) / M_PI);
	u = 1 - u;
	v = 1 - v;
	u = u * e->t[0];
	v = v * e->t[1];
	if (u * v < e->t[0] * e->t[1] && u > 0 && v > 0)
	{
		get_color2(e, u, v, &col);
		return (col);
	}
	return (obj->color);
}

t_rgb	texture_c(t_env *e, t_ray *ray, t_obj *obj)
{
	t_vec3	sub;
	double	u;
	double	v;
	t_rgb	d;

	sub = obj->inter;
	sub = vector_sub(obj->pos, sub);
	sub.y /= 2;
	u = sub.y * 0.5 + 0.5;
	v = -atan2(sub.x, sub.z) / (2 * M_PI) + 0.5;
	u = u < 0 ? -u : u;
	u = u - (int)u;
	u = u * e->t[0];
	v = v * e->t[1];
	u > 0 && v > 0 ? get_color2(e, u, v, &d) : 0;
	return (d);
}

t_rgb	texture_plan(t_env *e, t_ray *ray, t_obj *obj)
{
	double	u;
	double	v;
	t_vec3	d;

	d = obj->inter;
	if (obj->n.y == 0 && obj->n.x == 0)
		d.z = d.y;
	else if (obj->n.y == 0)
		d.x = d.y;
	d.x += e->key.move_tex.x;
	d.z += e->key.move_tex.z;
	u = (d.x) / (e->key.stretch.x + 2);
	v = (d.z) / (e->key.stretch.x + 2);
	if (e->key.repeat)
	{
		u = u < 0 ? -u : u;
		v = v < 0 ? -v : v;
		u = u - (int)u;
		v = v - (int)v;
	}
	if (u > 0 && u < 1 && v > 0 && v < 1)
		get_color2(e, u * e->t[0], v * e->t[1], &obj->color);
	return (obj->color);
}

t_rgb	choose_tex_type(t_obj *obj, t_env *e, t_ray *ray)
{
	t_rgb	col;

	if (obj->type == SPHERE)
		col = texture_sphere(e, ray, obj);
	else if (obj->type == PLAN)
		col = texture_plan(e, ray, obj);
	else if (obj->type == CYLINDER || obj->type == CONE)
		col = texture_c(e, ray, obj);
	return (col);
}
