/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:44:00 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/17 14:54:08 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	fill_light(char *str, t_light *light)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	check_error_l(tab);
	if ((light->pos.x = ft_atoi(tab[1]) / 1000.0f) < -200 || light->pos.x > 200)
		ft_error();
	if ((light->pos.y = ft_atoi(tab[2]) / 1000.0f) < -200 || light->pos.y > 200)
		ft_error();
	if ((light->pos.z = ft_atoi(tab[3]) / 1000.0f) < -200 || light->pos.z > 200)
		ft_error();
	if ((light->i = ft_atoi(tab[4]) / 1000.0f) < 0
			|| light->i > 1)
		ft_error();
	if (ft_strncmp("</LIGHT>", tab[5], 8))
		ft_error();
	clean_tab(tab);
}

void	fill_sphere(char *str, t_obj *obj)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	check_error_s(tab);
	if ((obj->pos.x = ft_atoi(tab[1]) / 1000.0f) < -200 || obj->pos.x > 200)
		ft_error();
	if ((obj->pos.y = ft_atoi(tab[2]) / 1000.0f) < -200 || obj->pos.y > 200)
		ft_error();
	if ((obj->pos.z = ft_atoi(tab[3]) / 1000.0f) < -200 || obj->pos.y > 200)
		ft_error();
	if ((obj->r = ft_atoi(tab[4]) / 1000.0f) < 1 || obj->r > 200)
		ft_error();
	if ((obj->color.red = ft_atoi(tab[5]) / 255.0f) > 1 || obj->color.red < 0)
		ft_error();
	if ((obj->color.green = ft_atoi(tab[6]) / 255.0f) > 1
			|| obj->color.green < 0)
		ft_error();
	if ((obj->color.blue = ft_atoi(tab[7]) / 255.0f) > 1 ||
			obj->color.blue < 0)
		ft_error();
	fill_sphere2(tab, obj);
	clean_tab(tab);
}

void	fill_plan(char *str, t_obj *obj)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	check_error_p(tab);
	if ((obj->pos.x = ft_atoi(tab[1]) / 1000.0f) < -200 || obj->pos.x > 200)
		ft_error();
	if ((obj->pos.y = ft_atoi(tab[2]) / 1000.0f) < -200 || obj->pos.y > 200)
		ft_error();
	if ((obj->pos.z = ft_atoi(tab[3]) / 1000.0f) < -200 || obj->pos.z > 200)
		ft_error();
	if ((obj->n.x = ft_atoi(tab[4])) < -200 || obj->n.x > 200)
		ft_error();
	if ((obj->n.y = ft_atoi(tab[5])) < -200 || obj->n.y > 200)
		ft_error();
	if ((obj->n.z = ft_atoi(tab[6])) < -200 || obj->n.z > 200)
		ft_error();
	fill_plan2(tab, obj);
	obj->nsave = obj->n;
	clean_tab(tab);
}

void	fill_cone(char *str, t_obj *obj)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	check_error(tab);
	if ((obj->pos.x = ft_atoi(tab[1]) / 1000.0f) < -200 || obj->pos.x > 200)
		ft_error();
	if ((obj->pos.y = ft_atoi(tab[2]) / 1000.0f) < -200 || obj->pos.y > 200)
		ft_error();
	if ((obj->pos.z = ft_atoi(tab[3]) / 1000.0f) < -200 || obj->pos.y > 200)
		ft_error();
	if ((obj->r = ft_atoi(tab[4])) < -180 || obj->r >= 180)
		ft_error();
	if ((obj->dir.x = ft_atoi(tab[5]) / 1000.0f) < -200 || obj->dir.x > 200)
		ft_error();
	if ((obj->dir.y = ft_atoi(tab[6]) / 1000.0f) < -200 || obj->dir.y > 200)
		ft_error();
	if ((obj->dir.z = ft_atoi(tab[7]) / 1000.0f) < -200 || obj->dir.z > 200)
		ft_error();
	if ((obj->color.red = ft_atoi(tab[8]) / 255.0f) > 1 || obj->color.red < 0)
		ft_error();
	fill_cone2(tab, obj);
	clean_tab(tab);
}

void	fill_cylinder(char *str, t_obj *obj)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	check_error(tab);
	if ((obj->pos.x = ft_atoi(tab[1]) / 1000.0f) < -200 || obj->pos.x > 200)
		ft_error();
	if ((obj->pos.y = ft_atoi(tab[2]) / 1000.0f) < -200 || obj->pos.y > 200)
		ft_error();
	if ((obj->pos.z = ft_atoi(tab[3]) / 1000.0f) < -200 || obj->pos.y > 200)
		ft_error();
	if ((obj->r = ft_atoi(tab[4]) / 1000.0f) < 1 || obj->pos.y > 200)
		ft_error();
	if ((obj->dir.x = ft_atoi(tab[5]) / 1000.0f) < -200 || obj->dir.x > 200)
		ft_error();
	if ((obj->dir.y = ft_atoi(tab[6]) / 1000.0f) < -200 || obj->dir.y > 200)
		ft_error();
	if ((obj->dir.z = ft_atoi(tab[7]) / 1000.0f) < -200 || obj->dir.z > 200)
		ft_error();
	if ((obj->color.red = ft_atoi(tab[8]) / 255.0f) > 1 || obj->color.red < 0)
		ft_error();
	fill_cylinder2(tab, obj);
	clean_tab(tab);
}
