/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:17:39 by yhemme            #+#    #+#             */
/*   Updated: 2018/04/09 17:17:01 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_obj	in_shadow(t_env *e, t_ray *ray_light, double pre_t, double t)
{
	t_obj	obj;
	double	a;

	obj = find_nearest(e, ray_light->dir, ray_light);
	compute_normal(e, ray_light, &obj);
	obj.t += pre_t;
	a = vector_dot(ray_light->dir, obj.n);
	if (a > 0)
		ray_light->org = vector_add(obj.inter, vector_mult(obj.n, 0.001));
	else
		ray_light->org = vector_add(obj.inter, vector_mult(obj.n, -0.001));
	if (obj.transp && t > obj.t)
		obj = in_shadow(e, ray_light, obj.t, t);
	return (obj);
}

double	specular(t_env *e, t_ray *prim, t_light light, t_obj *ob)
{
	t_vec3	r;
	t_vec3	l;
	t_vec3	v;
	double	s;

	l = normalize(vector_sub(light.pos, ob->inter));
	v = normalize(vector_sub(e->cam->pos, ob->inter));
	r = vector_mult(ob->n, 2 * vector_dot(ob->n, l));
	r = normalize(vector_sub(r, l));
	s = pow(max(vector_dot(v, r), 0.0f), 50);
	return (s);
}

double	shadow(t_env *e, t_ray *prim, t_light light, t_obj *ob)
{
	t_ray	ray_light;
	t_vec3	r;
	double	t;
	double	a;
	t_obj	obj;

	ray_light.org = ob->inter;
	ray_light.org = vector_add(ray_light.org, vector_mult(ob->n, 0.001));
	ray_light.dir = vector_sub(light.pos, ob->inter);
	t = vector_len(ray_light.dir);
	ray_light.dir = normalize(ray_light.dir);
	obj = in_shadow(e, &ray_light, 0, t);
	a = vector_dot(ob->n, ray_light.dir);
	r = vector_sub(vector_mult(ob->n, (2 *
					vector_dot(vector_mult(ray_light.dir, -1), ob->n))),
			vector_mult(ray_light.dir, -1));
	r = normalize(r);
	if (obj.t < 0.000005f || obj.t >= t)
	{
		if (a > 0)
			ob->dif = ob->dif + (a / (t * 0.004f * t) * (light.i * 0.5));
		ob->spec = ob->spec +
			specular(e, prim, light, ob) / (t * 0.0042f * t) * (light.i * 0.5);
	}
	return (1);
}

void	lights_apply(t_env *e, t_ray *prim, t_obj *obj)
{
	t_light	*light;
	double	li;
	double	tr;
	double	tr_tmp;

	tr = 0;
	obj->amb = 0.210 + e->amb;
	obj->dif = 0;
	obj->f_col.red = 0;
	obj->f_col.green = 0;
	obj->f_col.blue = 0;
	light = e->lights;
	obj->spec = 0;
	while (light)
	{
		tr_tmp = shadow(e, prim, *light, obj);
		light = light->next;
	}
	li = max(obj->dif, 0) + max(obj->spec, 0) + obj->amb;
	if (obj->type != -1)
	{
		obj->f_col.red = obj->color.red * li;
		obj->f_col.green = obj->color.green * li;
		obj->f_col.blue = obj->color.blue * li;
	}
}
