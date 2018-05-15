/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhemme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:19:55 by yhemme            #+#    #+#             */
/*   Updated: 2018/04/19 20:28:49 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	thread(t_env *e)
{
	pthread_t	thread[10];
	t_env		tab[10];
	int			i;

	i = 0;
	while (i < 10)
	{
		tab[i] = *e;
		tab[i].thread_id = i;
		pthread_create(&thread[i], NULL, raytrace, &tab[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}

int		mlx_main_loop(t_env *e)
{
	rotate(e);
	move(e);
	thread(e);
	hud(e);
	if (e->key.sepia == 1 || e->key.bw == 1
			|| e->key.cartoon == 1 || e->key.rainbow == 1)
		apply_filters(e);
	if (e->key.blur == 1)
		apply_blur(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	return (0);
}

int		exit_win(void)
{
	exit(EXIT_SUCCESS);
}

void	mlx(t_env *e)
{
	e->key.pix = 1;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTHHUD, HEIGHTHUD, "RT");
	e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img = mlx_get_data_addr(e->image, &(e->bpp), &(e->sl), &(e->ed));
	if (!(e->image2 =
			mlx_xpm_file_to_image(e->mlx, "./test.xpm", &e->t[0], &e->t[1])))
	{
		ft_putendl("No texture");
		exit(1);
	}
	e->img2 = mlx_get_data_addr(e->image2, &e->tmp[0], &e->tmp[1], &e->tmp[2]);
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 3, (1L << 3), key_release, e);
	mlx_hook(e->win, 17, 0, exit_win, e);
	mlx_loop_hook(e->mlx, mlx_main_loop, e);
	mlx_loop(e->mlx);
}

int		main(int ac, char **av)
{
	t_env		e;
	ssize_t		length;

	ft_memset(&e, 0, sizeof(t_env));
	e.lights = NULL;
	e.obj = NULL;
	if (ac != 2)
	{
		ft_putendl("Usage: ./RT [file.xml]");
		exit(1);
	}
	length = ft_strlen(av[1]);
	if (length < 5 || av[1][length - 1] != 'l' || av[1][length - 2] != 'm'
			|| av[1][length - 3] != 'x' || av[1][length - 4] != '.')
	{
		ft_putendl("Usage: ./RT [file.xml]");
		exit(1);
	}
	init_obj(&e, av[1]);
	mlx(&e);
	return (0);
}
