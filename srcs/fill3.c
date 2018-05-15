/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:45:49 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/16 14:12:58 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	fill_paraboloid(char *str, t_obj *obj)
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

void	fill_plan2(char **tab, t_obj *obj)
{
	if ((obj->color.red = ft_atoi(tab[7]) / 255.0f) > 1 || obj->color.red < 0)
		ft_error();
	if ((obj->color.green = ft_atoi(tab[8]) / 255.0f) > 1
			|| obj->color.green < 0)
		ft_error();
	if ((obj->color.blue = ft_atoi(tab[9]) / 255.0f) > 1
			|| obj->color.blue < 0)
		ft_error();
	if (((obj->transp = ft_atoi(tab[10]) / 100.0f) < 0) || obj->transp > 1)
		ft_error();
	if (((obj->reflect = ft_atoi(tab[11]) / 100.0f) < 0) || obj->reflect > 1)
		ft_error();
	if ((obj->perlin = ft_atoi(tab[12]) != 0) && obj->perlin != 1)
		ft_error();
	if ((obj->text = ft_atoi(tab[13]) != 0) && obj->text != 1)
		ft_error();
	if (ft_strncmp("</PLAN>", tab[14], 7))
		ft_error();
}

void	fill_sphere2(char **tab, t_obj *obj)
{
	if (((obj->transp = ft_atoi(tab[8]) / 100) < 0) || obj->transp > 1)
		ft_error();
	if (((obj->reflect = ft_atoi(tab[9]) / 100) < 0) || obj->reflect > 1)
		ft_error();
	if ((obj->perlin = ft_atoi(tab[10]) != 0) && obj->perlin != 1)
		ft_error();
	if ((obj->text = ft_atoi(tab[11]) != 0) && obj->text != 1)
		ft_error();
	if (ft_strncmp("</SPHERE>", tab[12], 9))
		ft_error();
}
