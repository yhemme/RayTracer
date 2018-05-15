/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:38:14 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/19 16:22:10 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	apply_transp(t_env *e, t_obj *obj, t_ray *primary)
{
	t_rgb	tmp;

	e->percent = 1 - obj->transp;
	tmp = transparency(e, primary, obj);
	(obj->type == PLAN && e->key.chess == 1) ? chess(e, obj) : 0;
	obj->perlin ? perlin(e, obj) : 0;
	obj->f_col.red = (obj->f_col.red * e->percent
			+ tmp.red * obj->transp);
	obj->f_col.green = (obj->f_col.green * e->percent
			+ tmp.green * obj->transp);
	obj->f_col.blue = (obj->f_col.blue * e->percent
			+ tmp.blue * obj->transp);
}

t_rgb	transparency(t_env *e, t_ray *ray, t_obj *c_obj)
{
	t_ray	new;
	t_obj	n_obj;
	t_rgb	tmp;
	double	percent;

	new.org = c_obj->inter;
	new.org = vector_add(new.org, vector_mult(ray->dir, 0.001));
	new.dir = ray->dir;
	n_obj = find_nearest(e, new.dir, &new);
	compute_normal(e, &new, &n_obj);
	n_obj.color = n_obj.text ? choose_tex_type(&n_obj, e, ray) : n_obj.color;
	n_obj.type == PLAN && e->key.chess == 1 ? chess(e, &n_obj) : 0;
	n_obj.perlin ? perlin(e, &n_obj) : 0;
	lights_apply(e, &new, &n_obj);
	percent = 1 - c_obj->transp;
	if (n_obj.transp)
	{
		tmp = transparency(e, &new, &n_obj);
		n_obj.f_col.red = (n_obj.f_col.red * percent + tmp.red * c_obj->transp);
		n_obj.f_col.green = (n_obj.f_col.green * percent
				+ tmp.green * c_obj->transp);
		n_obj.f_col.blue = (n_obj.f_col.blue * percent
				+ tmp.blue * c_obj->transp);
	}
	return (n_obj.f_col);
}
