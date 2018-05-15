/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:05:22 by yhemme            #+#    #+#             */
/*   Updated: 2018/04/10 14:33:14 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	compute_normal_plan(t_env *e, t_ray *ray, t_obj *p)
{
	t_vec3 inter;

	p->n = p->nsave;
	p->inter = vector_mult(ray->dir, p->t);
	p->inter = vector_add(p->inter, ray->org);
	p->n = normalize(p->n);
	if (e->key.sin == 1)
	{
		p->n.x += sin(p->inter.x) * 2;
		p->n = normalize(p->n);
	}
}

double	inter_plan(t_env *e, t_vec3 ray, t_obj *obj, t_vec3 cam)
{
	double	t;

	t = -((vector_dot(obj->n, vector_sub(cam, obj->pos)))
			/ vector_dot(obj->n, ray));
	return (t);
}

double	inter_disk(t_env *e, t_vec3 ray, t_obj *obj, t_vec3 cam)
{
	t_vec3	point;
	t_vec3	v;
	double	t;
	double	d2;
	double	radius;

	if ((t = inter_plan(e, ray, obj, cam)) > 0)
	{
		point = vector_add(vector_mult(ray, t), cam);
		v = vector_sub(point, obj->pos);
		d2 = vector_dot(v, v);
		if (sqrt(d2) <= obj->r)
			return (t);
	}
	return (-1);
}
