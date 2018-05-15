/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:24:34 by yhemme            #+#    #+#             */
/*   Updated: 2018/02/19 15:45:50 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		compute_normal_cone(t_ray ray, t_obj *c)
{
	double	m;
	t_vec3	x;
	t_vec3	b;
	double	k;

	c->inter = vector_add(vector_mult(ray.dir, c->t), ray.org);
	k = tan((c->r / 2) * M_PI / 180);
	x = vector_sub(ray.org, c->pos);
	m = vector_dot(ray.dir, c->dir) * c->t + vector_dot(x, c->dir);
	c->n = vector_sub(c->inter, c->pos);
	b = vector_mult(c->dir, (1 + k * k));
	b = vector_mult(c->dir, m);
	c->n = normalize(vector_sub(c->n, b));
}

double		inter_cone(t_vec3 ray, t_vec3 cam_p, t_obj *c)
{
	double		k;
	t_quadra	q;
	double		k1;
	t_vec3		x;

	c->dir = normalize(c->dir);
	x = vector_sub(cam_p, c->pos);
	k = tan((c->r / 2) * M_PI / 180);
	k1 = k * k + 1;
	q.a = vector_dot(ray, ray) - k1
		* vector_dot(ray, c->dir) * vector_dot(ray, c->dir);
	q.b = 2 * (vector_dot(ray, x) -
			k1 * vector_dot(ray, c->dir) * vector_dot(x, c->dir));
	q.c = vector_dot(x, x) - k1 * vector_dot(x, c->dir) * vector_dot(x, c->dir);
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
