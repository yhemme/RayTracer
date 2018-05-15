/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:37:51 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/19 18:07:04 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	apply_all(t_obj *n_obj, t_env *e, t_ray *ray, t_obj *c_obj)
{
	n_obj->type == PLAN && e->key.chess == 1 ? chess(e, n_obj) : 0;
	n_obj->perlin ? perlin(e, n_obj) : 0;
	e->percent2 = 1 - c_obj->reflect;
}

void	apply_reflect(t_env *e, t_obj *obj, t_ray *primary)
{
	t_rgb tmp;

	e->percent2 = 1 - obj->reflect;
	tmp = reflection(e, primary, obj, 1);
	(obj->type == PLAN && e->key.chess == 1) ? chess(e, obj) : 0;
	obj->perlin ? perlin(e, obj) : 0;
	obj->color.red = (obj->color.red * e->percent2 + tmp.red * obj->reflect);
	obj->color.green = (obj->color.green * e->percent2
	+ tmp.green * obj->reflect);
	obj->color.blue = (obj->color.blue * e->percent2 + tmp.blue * obj->reflect);
}

t_rgb	reflection(t_env *e, t_ray *ray, t_obj *c_obj, int depth)
{
	t_ray	new;
	t_obj	n_obj;
	t_rgb	tmp;

	new.org = vector_add(vector_mult(ray->dir, c_obj->t), ray->org);
	new.org = vector_add(new.org, vector_mult(c_obj->n, 0.001));
	new.dir = vector_add(ray->dir, vector_mult(c_obj->n,
				vector_dot(c_obj->n, ray->dir) * -2.0));
	n_obj = find_nearest(e, new.dir, &new);
	compute_normal(e, &new, &n_obj);
	n_obj.color = n_obj.text ? choose_tex_type(&n_obj, e, &new) : n_obj.color;
	apply_all(&n_obj, e, ray, c_obj);
	lights_apply(e, &new, &n_obj);
	apply_transp(e, &n_obj, ray);
	if (depth < 10 && n_obj.reflect)
	{
		tmp = reflection(e, &new, &n_obj, depth + 1);
		n_obj.f_col.red = (n_obj.f_col.red * e->percent2
		+ tmp.red * c_obj->reflect);
		n_obj.f_col.green = (n_obj.f_col.green * e->percent2
		+ tmp.green * c_obj->reflect);
		n_obj.f_col.blue = (n_obj.f_col.blue * e->percent2
		+ tmp.blue * c_obj->reflect);
	}
	return (n_obj.f_col);
}
