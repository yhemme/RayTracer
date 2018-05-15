/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:03:54 by yhemme            #+#    #+#             */
/*   Updated: 2018/05/15 14:56:11 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	malloc_error(void)
{
	ft_putstr("MALLOC ERROR\n");
	exit(0);
}

void	rotation_apply(t_env *e, t_vec3 *dir)
{
	*dir = x_rotation(*dir, e->cam->rotx);
	*dir = y_rotation(*dir, e->cam->roty);
	*dir = normalize(*dir);
}

void	angle_increase(t_env *e, double x, double y)
{
	e->cam->rotx += x;
	e->cam->roty += y;
	if (e->cam->rotx >= 360)
		e->cam->rotx -= 360;
	if (e->cam->roty >= 360)
		e->cam->roty -= 360;
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
