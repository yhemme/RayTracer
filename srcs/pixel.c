/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:24:05 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/17 14:45:58 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	pixelisation_norm(t_env *e, int x, int y, t_rgb *color)
{
	pixel_to_img(e, x + 3, y - 3, color);
	pixel_to_img(e, x + 3, y, color);
	pixel_to_img(e, x + 3, y + 3, color);
	pixel_to_img(e, x, y + 3, color);
	pixel_to_img(e, x + 3, y + 3, color);
	pixel_to_img(e, x - 4, y, color);
	pixel_to_img(e, x - 4, y - 4, color);
	pixel_to_img(e, x, y - 4, color);
	pixel_to_img(e, x + 4, y - 4, color);
	pixel_to_img(e, x + 4, y, color);
	pixel_to_img(e, x + 4, y + 4, color);
	pixel_to_img(e, x, y + 4, color);
	pixel_to_img(e, x + 4, y + 4, color);
}

void	put_pixelisation(t_env *e, int x, int y, t_rgb *color)
{
	pixel_to_img(e, x, y, color);
	pixel_to_img(e, x - 1, y, color);
	pixel_to_img(e, x - 1, y - 1, color);
	pixel_to_img(e, x, y - 1, color);
	pixel_to_img(e, x + 1, y - 1, color);
	pixel_to_img(e, x + 1, y, color);
	pixel_to_img(e, x + 1, y + 1, color);
	pixel_to_img(e, x, y + 1, color);
	pixel_to_img(e, x + 1, y + 1, color);
	pixel_to_img(e, x - 2, y, color);
	pixel_to_img(e, x - 2, y - 2, color);
	pixel_to_img(e, x, y - 2, color);
	pixel_to_img(e, x + 2, y - 2, color);
	pixel_to_img(e, x + 2, y, color);
	pixel_to_img(e, x + 2, y + 2, color);
	pixel_to_img(e, x, y + 2, color);
	pixel_to_img(e, x + 2, y + 2, color);
	pixel_to_img(e, x - 3, y, color);
	pixel_to_img(e, x - 3, y - 3, color);
	pixel_to_img(e, x, y - 3, color);
	pixelisation_norm(e, x, y, color);
}

t_rgb	a_a(int x, int y, t_env *e)
{
	t_ray	ray;
	double	i;
	double	j;
	t_rgb	col_tmp;
	t_rgb	col;

	col.red = 0;
	col.green = 0;
	col.blue = 0;
	i = -0.25;
	while (i < 0.26)
	{
		j = -0.25;
		while (j < 0.26)
		{
			compute_primary(x + i, y + j, e, &ray);
			col_tmp = intersect(e, &ray);
			col.red = col.red + (col_tmp.red / 9);
			col.green = col.green + (col_tmp.green / 9);
			col.blue = col.blue + (col_tmp.blue / 9);
			j += 0.25;
		}
		i += 0.25;
	}
	return (col);
}
