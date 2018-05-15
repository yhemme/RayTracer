/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 09:49:40 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/19 19:00:19 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	choose_type(t_obj *obj, char *str)
{
	if (!ft_strncmp("\t<SPHERE>", str, 9))
		obj->type = SPHERE;
	else if (!ft_strncmp("\t<DISK>", str, 7))
		obj->type = DISK;
	else if (!ft_strncmp("\t<PLAN>", str, 7))
		obj->type = PLAN;
	else if (!ft_strncmp("\t<CONE>", str, 7))
		obj->type = CONE;
	else if (!ft_strncmp("\t<CYLINDER>", str, 11))
		obj->type = CYLINDER;
	else if (!ft_strncmp("\t<PARABLOID>", str, 11))
		obj->type = PARABOLOID;
	else if (!ft_strncmp("\t<LIGHT>", str, 8))
		ft_error();
}

t_obj	*fill(char *str, t_obj *obj)
{
	choose_type(obj, str);
	if (obj->type == SPHERE)
		fill_sphere(str, obj);
	else if (obj->type == PLAN)
		fill_plan(str, obj);
	else if (obj->type == CONE)
		fill_cone(str, obj);
	else if (obj->type == CYLINDER)
		fill_cylinder(str, obj);
	else if (obj->type == DISK)
		fill_disk(str, obj);
	else if (obj->type == PARABOLOID)
		fill_paraboloid(str, obj);
	return (obj);
}

void	light_part(char **tab, int *i, int *j, t_env *e)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		malloc_error();
	fill_light(tab[*i], light);
	if (*j == 0)
	{
		e->lights = light;
		e->lights->next = NULL;
		*j += 1;
	}
	else
		add_light(e, light);
	*i += 1;
}

void	parse(t_env *e, char **tab)
{
	int		i;
	int		j;
	t_obj	*obj;

	i = 1;
	j = 0;
	if (ft_strncmp(tab[0], "<OBJ>", 5))
		ft_error();
	while (tab[i])
	{
		if (!tab[i + 1])
		{
			if (ft_strncmp(tab[i], "</OBJ>", 6))
				ft_error();
		}
		if (!ft_strncmp("\t<LIGHT>", tab[i], 8))
			light_part(tab, &i, &j, e);
		else
			parse2(e, tab, &i, obj);
	}
	clean_tab(tab);
}

void	init_obj(t_env *e, char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**tab;

	i = 0;
	fd = open(file, O_RDONLY);
	init_obj_null(e);
	if (get_next_line(fd, &line) <= 0)
		ft_error();
	else
	{
		free(line);
		++i;
		while (get_next_line(fd, &line) == 1 && i++ <= 20)
			free(line);
		if (i > 20)
			ft_error();
		close(fd);
		if (!(tab = malloc(sizeof(char*) * (i + 1))))
			malloc_error();
		stock(tab, line, file);
		parse(e, tab);
		close(fd);
	}
}
