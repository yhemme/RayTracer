/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:08:24 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/04/19 16:37:22 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	newscene(char *buf)
{
	t_env	e;

	ft_memset(&e, 0, sizeof(t_env));
	e.lights = NULL;
	e.obj = NULL;
	init_obj(&e, buf);
	mlx(&e);
}

void		readobject(t_env *e)
{
	t_obj	*obj;
	char	buf[4097];
	ssize_t	rd;
	int		fd;

	rd = read(STDIN_FILENO, buf, 4096);
	if (buf[rd - 1] == '\n')
		buf[rd - 1] = '\0';
	else
		buf[rd] = '\0';
	fd = open(buf, O_RDONLY);
	if (fd >= 0)
		newscene(buf);
	else
	{
		if (!(obj = malloc(sizeof(t_obj))))
			malloc_error();
		obj = fill(buf, obj);
		add_obj(e, obj);
	}
}

t_rgb		intersect(t_env *e, t_ray *primary)
{
	t_obj	tmp;

	tmp = find_nearest(e, primary->dir, primary);
	compute_normal(e, primary, &tmp);
	tmp.color = tmp.text ? choose_tex_type(&tmp, e, primary) : tmp.color;
	tmp.type == PLAN && e->key.chess == 1 ? chess(e, &tmp) : 0;
	tmp.perlin ? perlin(e, &tmp) : 0;
	tmp.reflect ? apply_reflect(e, &tmp, primary) : 0;
	lights_apply(e, primary, &tmp);
	tmp.transp ? apply_transp(e, &tmp, primary) : 0;
	return (tmp.f_col);
}

void		parse2(t_env *e, char **tab, int *i, t_obj *obj)
{
	if (!(obj = malloc(sizeof(t_obj))))
		malloc_error();
	obj = fill(tab[*i], obj);
	if (!e->obj)
	{
		e->obj = obj;
		e->obj->next = NULL;
	}
	else
		add_obj(e, obj);
	(*i)++;
}
