/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:34:54 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/09 10:52:03 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		choose_variation(t_obj *obj, int *b, double *c)
{
	if (obj->type == PLAN && obj->n.y == 1)
	{
		*b = 50;
		*c = 0.5;
	}
	else
	{
		*b = 5;
		*c = 0.1;
	}
}

void		linear_interpolations(t_perlin *p)
{
	p->x00 = linear_interpolate(p->g000, p->g100, p->u);
	p->x10 = linear_interpolate(p->g010, p->g110, p->u);
	p->x01 = linear_interpolate(p->g001, p->g101, p->u);
	p->x11 = linear_interpolate(p->g011, p->g111, p->u);
	p->xy0 = linear_interpolate(p->x00, p->x10, p->v);
	p->xy1 = linear_interpolate(p->x01, p->x11, p->v);
	p->xyz = linear_interpolate(p->xy0, p->xy1, p->w);
}

double		quintic_poly(double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

void		perlin(t_env *e, t_obj *obj)
{
	int		a;
	int		b;
	double	c;

	choose_variation(obj, &b, &c);
	a = 2;
	obj->n.x = (b * obj->n.x + smooth_noise_3d(obj->inter.x -
		a, obj->inter.y, obj->inter.z, c))
		- (obj->n.x + smooth_noise_3d(obj->inter.x + a, obj->inter.y,
			obj->inter.z, c));
	obj->n.y = (b * obj->n.y + smooth_noise_3d(obj->inter.x, obj->inter.y -
		a, obj->inter.z, c))
		- (obj->n.y + smooth_noise_3d(obj->inter.x, obj->inter.y
			+ a, obj->inter.z, c));
	obj->n.z = (b * obj->n.z + smooth_noise_3d(obj->inter.x, obj->inter.y,
		obj->inter.z - a, c))
		- (obj->n.z + smooth_noise_3d(obj->inter.x, obj->inter.y,
			obj->inter.z + a, c));
	obj->n = normalize(obj->n);
}
