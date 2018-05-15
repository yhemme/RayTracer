/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:00:09 by yhemme            #+#    #+#             */
/*   Updated: 2018/02/19 16:19:01 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec3	y_rotation(t_vec3 vec, double angle)
{
	t_vec3	new;
	double	ang;

	ang = angle * M_PI / 180;
	new.x = vec.x * cos(ang) + vec.z * sin(ang);
	new.y = vec.y;
	new.z = vec.z * cos(ang) - vec.x * sin(ang);
	return (new);
}

t_vec3	x_rotation(t_vec3 vec, double angle)
{
	t_vec3	new;
	double	ang;

	ang = angle * M_PI / 180;
	new.x = vec.x;
	new.y = vec.y * cos(ang) - vec.z * sin(ang);
	new.z = vec.y * sin(ang) + vec.z * cos(ang);
	return (new);
}
