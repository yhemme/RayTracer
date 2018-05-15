/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:40:29 by yhemme            #+#    #+#             */
/*   Updated: 2018/02/19 16:16:06 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec3	vector_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

double	vector_len(t_vec3 v1)
{
	double	len;

	len = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	return (len);
}

t_vec3	normalize(t_vec3 v)
{
	t_vec3	new;
	double	len;

	len = vector_len(v);
	new.x = v.x / len;
	new.y = v.y / len;
	new.z = v.z / len;
	return (new);
}

void	up_vec_create(t_vec3 *vec)
{
	vec->x = 0;
	vec->y = 1;
	vec->z = 0;
}

void	right_vec_create(t_vec3 *vec)
{
	vec->x = 1;
	vec->y = 0;
	vec->z = 0;
}
