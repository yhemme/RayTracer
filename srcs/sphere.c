/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:51:53 by yhemme            #+#    #+#             */
/*   Updated: 2018/03/16 10:44:47 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	compute_normal_sphere(t_env *e, t_ray *ray, t_obj *s)
{
	s->inter = vector_mult(ray->dir, s->t);
	s->inter = vector_add(s->inter, ray->org);
	s->n = vector_sub(s->inter, s->pos);
	s->n = normalize(s->n);
}

void	solve_quadratic(t_quadra *s)
{
	if (s->discr == 0)
	{
		s->x0 = -0.5 * s->b / s->a;
		s->x1 = -0.5 * s->b / s->a;
	}
	else
	{
		if (s->b > 0)
			s->q = -0.5 * (s->b + sqrt(s->discr));
		else
			s->q = -0.5 * (s->b - sqrt(s->discr));
		s->x0 = s->q / s->a;
		s->x1 = s->c / s->q;
	}
}

double	inter_sphere(t_env *e, t_vec3 ray, t_obj *obj, t_vec3 o)
{
	t_quadra	s;
	t_vec3		l;
	double		radius;

	radius = obj->r;
	l = vector_sub(o, obj->pos);
	s.a = vector_dot(ray, ray);
	s.b = 2 * vector_dot(ray, l);
	s.c = vector_dot(l, l) - radius;
	s.discr = s.b * s.b - 4 * s.a * s.c;
	if (s.discr < 0)
		return (-1);
	solve_quadratic(&s);
	if (s.x0 > s.x1)
		ft_swap_double(&s.x0, &s.x1);
	if (s.x0 < 0)
		ft_swap_double(&s.x0, &s.x1);
	return (s.x0);
}
