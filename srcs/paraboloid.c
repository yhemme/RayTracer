/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:21:49 by thabdoul          #+#    #+#             */
/*   Updated: 2018/03/16 14:48:46 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	compute_normal_paraboloid(t_ray ray, t_obj *c)
{
	double	m;
	t_vec3	x;
	t_vec3	b;
	double	k;

	c->inter = vector_add(vector_mult(ray.dir, c->t), ray.org);
	k = vector_dot(x, c->dir);
	x = vector_sub(ray.org, c->pos);
	m = vector_dot(ray.dir, c->dir) * c->t + vector_dot(x, c->dir);
	c->n = vector_sub(c->inter, c->pos);
	b = vector_mult(c->dir, vector_dot(ray.dir, c->dir));
	b = vector_mult(c->dir, m);
	c->n = normalize(vector_sub(c->n, b));
}

double	inter_paraboloid(t_vec3 ray, t_vec3 cam, t_obj *c)
{
	double		k;
	double		k1;
	t_quadra	q;
	t_vec3		x;

	x = vector_sub(cam, c->pos);
	k = vector_dot(x, c->dir);
	k1 = vector_dot(ray, c->dir);
	q.a = vector_dot(ray, ray) - k1 * k1;
	q.b = 2 * (vector_dot(ray, x) - k1 * (k + 2 * c->r));
	q.c = vector_dot(x, x) - k * (k + 4 * c->r);
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
