/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:29:27 by thabdoul          #+#    #+#             */
/*   Updated: 2018/04/19 16:21:47 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_error(void)
{
	ft_putendl("Invalid file");
	exit(1);
}

void	check_error_s(char **tab)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!tab[1] || !tab[2] || !tab[3] || !tab[4] ||
			!tab[5] || !tab[6] || !tab[7] || !tab[8] || !tab[9] ||
			!tab[10] || !tab[11] || !tab[12])
		ft_error();
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 0 && tab[i][0] != '-'
					&& tab[i][0] != '<')
				ft_error();
			j++;
		}
		i++;
	}
}

void	check_error_l(char **tab)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!tab[1] || !tab[2] || !tab[3] || !tab[4])
		ft_error();
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 0 && tab[i][0] != '-'
					&& tab[i][0] != '<')
				ft_error();
			j++;
		}
		i++;
	}
}

void	check_error_p(char **tab)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!tab[1] || !tab[2] || !tab[3] || !tab[4] ||
				!tab[5] || !tab[6] || !tab[7] || !tab[8]
				|| !tab[9] || !tab[10] || !tab[11] || !tab[12]
				|| !tab[13] || !tab[14])
		ft_error();
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 0 && tab[i][0] != '-'
					&& tab[i][0] != '<')
				ft_error();
			j++;
		}
		i++;
	}
}

void	check_error(char **tab)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!tab[1] || !tab[2] || !tab[3] || !tab[4] || !tab[5] || !tab[6] ||
			!tab[7] || !tab[8] || !tab[9] || !tab[10] ||
			!tab[11] || !tab[12] || !tab[12] || !tab[13]
			|| !tab[14] || !tab[15])
		ft_error();
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 0 && tab[i][0] != '-'
					&& tab[i][0] != '<')
				ft_error();
			j++;
		}
		i++;
	}
}
