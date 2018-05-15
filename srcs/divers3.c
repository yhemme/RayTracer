/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 09:24:47 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/19 16:54:46 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	clean_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	init_obj_null(t_env *e)
{
	if (!(e->obj_null = (t_obj*)malloc(sizeof(t_obj))))
		malloc_error();
	e->obj = NULL;
	e->obj_null->color.red = 0.0f;
	e->obj_null->color.green = 0.0f;
	e->obj_null->color.blue = 0.0f;
	e->obj_null->type = -1.0f;
	e->obj_null->transp = 0;
	init_cam(e);
}

void	add_obj(t_env *e, t_obj *obj)
{
	t_obj	*cur;

	cur = e->obj;
	while (cur->next)
		cur = cur->next;
	cur->next = obj;
	obj->next = NULL;
}

void	add_light(t_env *e, t_light *light)
{
	t_light	*cur;

	cur = e->lights;
	while (cur->next)
		cur = cur->next;
	cur->next = light;
	light->next = NULL;
}

void	check_error_d(char **tab)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!tab[1] || !tab[2] || !tab[3] || !tab[4] ||
				!tab[5] || !tab[6] || !tab[7] || !tab[8] || !tab[9] || !tab[10]
				|| !tab[11] || !tab[12] || !tab[13])
		ft_error();
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 0 && tab[i][0] != '-'
					&& tab[i][0] != '<')
				ft_error();
			j++;
		}
		i++;
	}
}
