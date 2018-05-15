/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_filters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:53:39 by yhemme            #+#    #+#             */
/*   Updated: 2018/05/15 14:55:10 by yhemme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	apply_blur(t_env *e)
{
	int		x;
	int		y;
	t_rgb	color;

	x = 3;
	while (x < WIDTH)
	{
		y = 3;
		while (y < HEIGHT)
		{
			get_color_sq(e, x, y, &color);
			pixel_to_img(e, x, y, &color);
			y++;
		}
		x++;
	}
}

void	apply_filters(t_env *e)
{
	int		x;
	int		y;
	t_rgb	color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			get_color(e->img, x, y, &color);
			if (e->key.sepia == 1)
				filter_sepia(&color, e);
			if (e->key.bw == 1)
				filterbw(&color, e);
			if (e->key.cartoon == 1)
				filter_cartoon(&color, e);
			pixel_to_img(e, x, y, &color);
			y++;
		}
		x++;
	}
}

void	screenshot(t_env *e)
{
	int				x;
	int				y;
	t_rgb			color;
	unsigned char	img[3 * WIDTH * HEIGHT];

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			get_color(e->img, x, y, &color);
			img[(x + y * WIDTH) * 3 + 0] = (unsigned char)min(color.red *
					255.0f, 255.0f);
			img[(x + y * WIDTH) * 3 + 1] = (unsigned char)min(color.green *
					255.0f, 255.0f);
			img[(x + y * WIDTH) * 3 + 2] = (unsigned char)min(color.blue *
					255.0f, 255.0f);
			y++;
		}
		x++;
	}
	saveppm("screen.ppm", img);
	ft_putendl("\033[32;01mScreen saved\033[00m");
}
