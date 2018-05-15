/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlxlib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:35:48 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/19 16:17:46 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	pixel_to_img(t_env *e, int x, int y, t_rgb *color)
{
	int		i;

	i = 4 * (x + (y * WIDTH));
	if (x >= 0 && y >= 0
			&& x < WIDTH && y < HEIGHT)
	{
		e->img[i] = (unsigned char)min(color->blue * 255, 255);
		e->img[i + 1] = (unsigned char)min(color->green * 255, 255);
		e->img[i + 2] = (unsigned char)min(color->red * 255, 255);
	}
}

void	get_color(char *img, int x, int y, t_rgb *color)
{
	int		i;

	i = 4 * (x + (y * WIDTH));
	if (x < WIDTH && y < HEIGHT)
	{
		color->blue = (unsigned char)img[i] / 255.0f;
		color->green = (unsigned char)img[i + 1] / 255.0f;
		color->red = (unsigned char)img[i + 2] / 255.0f;
	}
}

void	get_color2(t_env *e, int x, int y, t_rgb *color)
{
	int		i;

	i = 4 * (x + (y * e->t[0]));
	if (x < e->t[1] && y < e->t[0])
	{
		color->blue = (unsigned char)e->img2[i] / 255.0f;
		color->green = (unsigned char)e->img2[i + 1] / 255.0f;
		color->red = (unsigned char)e->img2[i + 2] / 255.0f;
	}
}

void	get_color_sq(t_env *e, int x, int y, t_rgb *color)
{
	int		i;
	t_rgb	colors[9];

	color->blue = 0.0f;
	color->green = 0.0f;
	color->red = 0.0f;
	get_color(e->img, x - 3, y, &colors[0]);
	get_color(e->img, x - 3, y + 3, &colors[1]);
	get_color(e->img, x, y + 3, &colors[2]);
	get_color(e->img, x + 3, y + 3, &colors[3]);
	get_color(e->img, x + 3, y, &colors[4]);
	get_color(e->img, x + 3, y + 3, &colors[5]);
	get_color(e->img, x, y - 3, &colors[6]);
	get_color(e->img, x - 3, y - 3, &colors[7]);
	get_color(e->img, x, y, &colors[8]);
	i = 0;
	while (i < 9)
	{
		color->blue += (colors[i].blue / 9.0f);
		color->green += (colors[i].green / 9.0f);
		color->red += (colors[i].red / 9.0f);
		i++;
	}
}

void	get_color_msaa(t_env *e, int x, int y, t_rgb *color)
{
	int		i;
	t_rgb	colors[9];

	color->blue = 0.0f;
	color->green = 0.0f;
	color->red = 0.0f;
	get_color(e->img, x - 1, y, &colors[0]);
	get_color(e->img, x - 1, y + 1, &colors[1]);
	get_color(e->img, x, y + 1, &colors[2]);
	get_color(e->img, x + 1, y + 1, &colors[3]);
	get_color(e->img, x + 1, y, &colors[4]);
	get_color(e->img, x + 1, y + 1, &colors[5]);
	get_color(e->img, x, y - 1, &colors[6]);
	get_color(e->img, x - 1, y - 1, &colors[7]);
	get_color(e->img, x, y, &colors[8]);
	i = 0;
	while (i < 9)
	{
		color->blue += (colors[i].blue / 9.0f);
		color->green += (colors[i].green / 9.0f);
		color->red += (colors[i].red / 9.0f);
		i++;
	}
}
