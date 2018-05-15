/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:28:00 by yhemme            #+#    #+#             */
/*   Updated: 2018/04/12 13:57:04 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	compute_normal(t_env *e, t_ray *ray, t_obj *obj)
{
	if (obj->type == SPHERE)
		compute_normal_sphere(e, ray, obj);
	else if (obj->type == PLAN)
		compute_normal_plan(e, ray, obj);
	else if (obj->type == DISK)
		compute_normal_plan(e, ray, obj);
	else if (obj->type == CYLINDER)
		compute_normal_cylinder(*ray, obj);
	else if (obj->type == CONE)
		compute_normal_cone(*ray, obj);
	else if (obj->type == PARABOLOID)
		compute_normal_paraboloid(*ray, obj);
}

void	compute_primary(double x, double y, t_env *e, t_ray *ray)
{
	t_vec3	pixel;

	pixel.x = (x + 0.5) / WIDTH;
	pixel.y = (y + 0.5) / HEIGHT;
	pixel.x = (2 * pixel.x) - 1;
	pixel.y = 1 - (2 * pixel.y);
	pixel.x *= tan(FOV * 0.5 * M_PI / 180) * RATIO;
	pixel.y *= tan(FOV * 0.5 * M_PI / 180);
	pixel.z = -1;
	pixel = vector_add(pixel, e->cam->pos);
	ray->org = e->cam->pos;
	ray->dir = normalize(vector_sub(pixel, e->cam->pos));
	rotation_apply(e, &ray->dir);
}

double	distance(t_env *e, t_vec3 dir, t_obj *obj, t_ray *ray)
{
	double	t;

	t = D_MAX;
	if (obj->type == SPHERE)
		t = inter_sphere(e, dir, obj, ray->org);
	else if (obj->type == PLAN)
		t = inter_plan(e, dir, obj, ray->org);
	else if (obj->type == CYLINDER)
		t = inter_cylinder(dir, ray->org, obj);
	else if (obj->type == CONE)
		t = inter_cone(dir, ray->org, obj);
	else if (obj->type == DISK)
		t = inter_disk(e, dir, obj, ray->org);
	else if (obj->type == PARABOLOID)
		t = inter_paraboloid(dir, ray->org, obj);
	return (t);
}

t_obj	find_nearest(t_env *e, t_vec3 dir, t_ray *ray)
{
	double	t_cur;
	double	t;
	t_obj	*obj;
	t_obj	ret;

	ret = *e->obj_null;
	obj = e->obj;
	t_cur = D_MAX;
	while (obj)
	{
		t = distance(e, dir, obj, ray);
		if (t > 0 && t < t_cur)
		{
			t_cur = t;
			ret = *obj;
		}
		obj = obj->next;
	}
	ret.t = t_cur;
	return (ret);
}

void	*raytrace(void *ev)
{
	int		x;
	int		y;
	t_ray	primary;
	t_obj	obj;
	t_env	e;

	e = *(t_env*)ev;
	e.px = e.key.pix ? 4 : 1;
	x = 0;
	while (x < WIDTH)
	{
		y = HEIGHT / 10 * e.thread_id;
		while (y < HEIGHT / 10 * (e.thread_id + 1))
		{
			compute_primary(x, y, &e, &primary);
			obj.f_col = e.key.rainbow ? a_a(x, y, &e) : intersect(&e, &primary);
			if (e.key.pix == 1)
				put_pixelisation(&e, x, y, &obj.f_col);
			pixel_to_img(&e, x, y, &obj.f_col);
			y += e.px;
		}
		x += e.px;
	}
	pthread_exit(NULL);
}
