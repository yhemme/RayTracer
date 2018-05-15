/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:17:43 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/04/19 13:17:08 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#define DELIM "========================="
#define COLOR 0x0ffffff

static void			hudplus(t_env *e, int x, int y)
{
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "F16 : Screenshot");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "W : Move forward");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "S : Move backward");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "A : Move left");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "D : Move right");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "UP : Rotate up");
	mlx_string_put(e->mlx, e->win, x += 200, y = HEIGHT, COLOR, "|");
	mlx_string_put(e->mlx, e->win, x += 20, y += 20,
			COLOR, "DOWN : rotate down");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "LEFT : rotate left");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "RIGHT : rotate right");
}

static void			hudbottom(t_env *e)
{
	int x;
	int y;

	y = HEIGHT;
	x = 0;
	mlx_string_put(e->mlx, e->win, x += 10, y += 20, COLOR, "P : Pixelisation");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "+/- : Light intensity");
	mlx_string_put(e->mlx, e->win, x, y += 20,
			COLOR, "R : Read for new object");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "1 : Greyscale");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "2 : Sepia");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "3 : Cartoon");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "4 : Blur");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "5 : Sin");
	mlx_string_put(e->mlx, e->win, x += 250, y = HEIGHT, COLOR, "|");
	mlx_string_put(e->mlx, e->win, x += 20, y += 20, COLOR, "6 : Chess");
	mlx_string_put(e->mlx, e->win, x, y += 20, COLOR, "7 : Anti-Aliasing");
	hudplus(e, x, y);
}

static void			hudplus2(t_env *e, int y)
{
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20,
			COLOR, e->key.sepia ? "Sepia : On" : "Sepia : off");
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20,
			COLOR, e->key.sin ? "Sin : On" : "Sin : Off");
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20,
			COLOR, e->key.rainbow ? "A-A : On" : "A-A : Off");
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20,
			COLOR, e->key.bw ? "Greyscale : On" : "Greyscale : Off");
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20, COLOR, "Intensity light : ");
	mlx_string_put(e->mlx, e->win, WIDTH + 180, y,
			COLOR, ft_itoa((int)(e->amb * 100)));
	hudbottom(e);
}

void				hud(t_env *e)
{
	int y;

	y = 0;
	mlx_clear_window(e->mlx, e->win);
	mlx_string_put(e->mlx, e->win, WIDTH + WIDTH / 8, y += 10, COLOR, "RT");
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20,
			COLOR, DELIM);
	mlx_string_put(e->mlx, e->win, WIDTH, HEIGHT - 15,
			COLOR, DELIM);
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20,
			COLOR, e->key.pix ? "Pixelisation : On" : "Pixelisation : Off");
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20,
			COLOR, e->key.blur ? "Blur : On" : "Blur : Off");
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20,
			COLOR, e->key.cartoon ? "Cartoon : on" : "Cartoon : Off");
	mlx_string_put(e->mlx, e->win, WIDTH, y += 20,
			COLOR, e->key.chess ? "Chess : On" : "Chess : Off");
	hudplus2(e, y);
}
