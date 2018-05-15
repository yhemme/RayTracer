/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:01:58 by thabdoul          #+#    #+#             */
/*   Updated: 2018/03/09 10:51:12 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	saveppm(char *filename, unsigned char *img)
{
	FILE	*f;

	f = fopen(filename, "wb");
	fprintf(f, "P6 %d %d %d\n", WIDTH, HEIGHT, 255);
	fwrite(img, 3, WIDTH * HEIGHT, f);
	fclose(f);
}
