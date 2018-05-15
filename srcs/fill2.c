/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:32:26 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/19 18:58:38 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	fill_cone2(char **tab, t_obj *obj)
{
	if ((obj->color.green = ft_atoi(tab[9]) / 255.0f) > 1
			|| obj->color.green < 0)
		ft_error();
	if ((obj->color.blue = ft_atoi(tab[10]) / 255.0f) > 1
			|| obj->color.blue < 0)
		ft_error();
	if (((obj->transp = ft_atoi(tab[11]) / 100) < 0) || obj->transp > 1)
		ft_error();
	if (((obj->reflect = ft_atoi(tab[12]) / 100) < 0) || obj->reflect > 1)
		ft_error();
	if ((obj->perlin = ft_atoi(tab[13]) != 0) && obj->perlin != 1)
		ft_error();
	if ((obj->text = ft_atoi(tab[14]) != 0) && obj->text != 1)
		ft_error();
	if (ft_strncmp("</CONE>", tab[15], 7) &&
			ft_strncmp("</PARABOLOID>", tab[15], 13))
		ft_error();
}

void	fill_cylinder2(char **tab, t_obj *obj)
{
	if ((obj->color.green = ft_atoi(tab[9]) / 255.0f) > 1
			|| obj->color.green < 0)
		ft_error();
	if ((obj->color.blue = ft_atoi(tab[10]) / 255.0f) > 1
			|| obj->color.blue < 0)
		ft_error();
	if (((obj->transp = ft_atoi(tab[11]) / 100.0f) < 0) || obj->transp > 1)
		ft_error();
	if (((obj->reflect = ft_atoi(tab[12]) / 100) < 0) || obj->reflect > 1)
		ft_error();
	if ((obj->perlin = ft_atoi(tab[13]) != 0) && obj->perlin != 1)
		ft_error();
	if ((obj->text = ft_atoi(tab[14]) != 0) && obj->text != 1)
		ft_error();
	if (ft_strncmp("</CYLINDER>", tab[15], 11))
		ft_error();
}

void	stock(char **tab, char *line, char *file)
{
	int i;
	int fd;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab[i] = ft_strdup(line);
		i++;
		free(line);
	}
	tab[i] = NULL;
	close(fd);
}

void	fill_disk2(char **tab, t_obj *obj)
{
	if ((obj->color.red = ft_atoi(tab[8]) / 255.0f) > 1 || obj->color.red < 0)
		ft_error();
	if ((obj->color.green = ft_atoi(tab[9]) / 255.0f) > 1
			|| obj->color.green < 0)
		ft_error();
	if ((obj->color.blue = ft_atoi(tab[10]) / 255.0f) > 1
			|| obj->color.blue < 0)
		ft_error();
	if (((obj->transp = ft_atoi(tab[11]) / 100) < 0) || obj->transp > 1)
		ft_error();
	if (((obj->reflect = ft_atoi(tab[12]) / 100) < 0) || obj->reflect > 1)
		ft_error();
	if ((obj->perlin = ft_atoi(tab[13]) != 0) && obj->perlin != 1)
		ft_error();
	if (ft_strncmp("</DISK>", tab[14], 7))
		ft_error();
	obj->text = 0;
}

void	fill_disk(char *str, t_obj *obj)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	check_error_d(tab);
	if ((obj->pos.x = ft_atoi(tab[1]) / 1000.0f) < -200 || obj->pos.x > 200)
		ft_error();
	if ((obj->pos.y = ft_atoi(tab[2]) / 1000.0f) < -200 || obj->pos.y > 200)
		ft_error();
	if ((obj->pos.z = ft_atoi(tab[3]) / 1000.0f) < -200 || obj->pos.z > 200)
		ft_error();
	if ((obj->r = ft_atoi(tab[4]) / 1000.0f) < 1.1 || obj->r > 200)
		ft_error();
	if ((obj->n.x = ft_atoi(tab[5])) < -200 || obj->n.x > 200)
		ft_error();
	if ((obj->n.y = ft_atoi(tab[6])) < -200 || obj->n.y > 200)
		ft_error();
	if ((obj->n.z = ft_atoi(tab[7])) < -200 || obj->n.z > 200)
		ft_error();
	fill_disk2(tab, obj);
	clean_tab(tab);
}
