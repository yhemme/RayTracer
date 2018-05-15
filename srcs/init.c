/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:07:51 by yhemme            #+#    #+#             */
/*   Updated: 2018/02/27 10:51:08 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	init_cam(t_env *e)
{
	if ((e->cam = malloc(sizeof(t_cam))) == NULL)
		malloc_error();
	e->cam->pos.x = 0.0f;
	e->cam->pos.y = 0.0f;
	e->cam->pos.z = 0.0f;
	e->cam->rotx = 0.0f;
	e->cam->roty = 0.0f;
}
