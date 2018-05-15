/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:33:46 by thabdoul          #+#    #+#             */
/*   Updated: 2018/03/13 15:27:44 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	filter_sepia(t_rgb *color, t_env *e)
{
	color->red = (color->red + 160.0f / 255.0f) / 2.0f;
	color->green = (color->green + 82.0f / 255.0f) / 2.0f;
	color->blue = (color->blue + 45.0f / 255.0f) / 2.0f;
}

void	filter_cartoon2(t_rgb *color)
{
	if (color->red > 100 && color->red <= 200)
		color->red = 150;
	if (color->red > 200 && color->red <= 240)
		color->red = 225;
	if (color->red >= 255 || color->red > 240)
		color->red = 255;
	if (color->green > 0 && color->green <= 50)
		color->green = 25;
	if (color->green > 50 && color->green <= 100)
		color->green = 75;
	if (color->green > 100 && color->green <= 200)
		color->green = 150;
	if (color->green > 200 && color->green <= 240)
		color->green = 225;
	if (color->green >= 255 || color->green > 240)
		color->green = 255;
	if (color->blue > 0 && color->blue <= 50)
		color->blue = 25;
	if (color->blue > 50 && color->blue <= 100)
		color->blue = 75;
	if (color->blue > 100 && color->blue <= 200)
		color->blue = 150;
}

void	filter_cartoon(t_rgb *color, t_env *e)
{
	color->red *= 255.0f;
	color->green *= 255.0f;
	color->blue *= 255.0f;
	if (color->red > 0 && color->red <= 50)
		color->red = 25;
	if (color->red > 50 && color->red <= 100)
		color->red = 75;
	filter_cartoon2(color);
	if (color->blue > 200 && color->blue <= 240)
		color->blue = 225;
	if (color->blue >= 255 || color->blue > 240)
		color->blue = 255;
	color->red /= 255.0f;
	color->blue /= 255.0f;
	color->green /= 255.0f;
}

void	filterbw(t_rgb *color, t_env *e)
{
	double	median;

	median = color->red + color->blue + color->green;
	median /= 3.0f;
	color->red = median;
	color->green = median;
	color->blue = median;
}
