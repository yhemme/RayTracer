/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:47:37 by yhemme            #+#    #+#             */
/*   Updated: 2018/02/19 16:20:25 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	compute_normal_cylinder(t_ray ray, t_obj *c)
{
	double	m;
	t_vec3	x;

	c->inter = vector_add(vector_mult(ray.dir, c->t), ray.org);
	x = vector_sub(ray.org, c->pos);
	m = vector_dot(ray.dir, c->dir) * c->t + vector_dot(x, c->dir);
	c->n = vector_sub(c->inter, c->pos);
	c->n = vector_sub(c->n, vector_mult(c->dir, m));
}

double	inter_cylinder(t_vec3 ray, t_vec3 cam_p, t_obj *obj)
{
	t_quadra	q;
	t_vec3		x;

	obj->dir = normalize(obj->dir);
	x = vector_sub(cam_p, obj->pos);
	q.a = vector_dot(ray, ray) -
		vector_dot(ray, obj->dir) * vector_dot(ray, obj->dir);
	q.c = vector_dot(x, x) -
		vector_dot(x, obj->dir) * vector_dot(x, obj->dir) - obj->r * obj->r;
	q.b = 2 * (vector_dot(ray, x) -
		vector_dot(ray, obj->dir) * vector_dot(x, obj->dir));
	q.discr = q.b * q.b - 4 * q.a * q.c;
	if (q.discr < 0)
		return (-1);
	solve_quadratic(&q);
	if (q.x0 > q.x1)
		ft_swap_double(&q.x0, &q.x1);
	if (q.x0 < 0)
		ft_swap_double(&q.x0, &q.x1);
	return (q.x0);
}
