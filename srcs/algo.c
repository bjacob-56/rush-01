/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:24:30 by bjacob            #+#    #+#             */
/*   Updated: 2021/04/12 11:24:30 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush01.h"

static int	check_nbr(char **map_origin, int i, int j)
{
	int	height;

	height = map_origin[i][j];
	return (i && j
		&& height == map_origin[i - 1][j]
		&& height == map_origin[i][j - 1]
		&& height == map_origin[i - 1][j - 1]);
}

static int	 get_new_size(t_rush *rush, int val1, int val2, int val3)
{
	int	val;

	if (val1 <= val2)
	{
		if (val1 <= val3)
			val = val1;
		val = val3;
	}
	else if (val2 <= val3)
		val = val2;
	else
		val = val3;
	rush->map_modif[i][j] = val;
	if (val > rush->max)
	{
		rush->max = val;
		rush->i_max = i;
		rush->j_max = j;
	}
}

static	void	place_camp(t_rush *rush, char **map_o, char c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rush->max)
	{
		j = -1;
		while (++j < rush->max)
			map_o[rush->i_max - i][rush->j_max - j] = c;
	}
}

void	algo(t_rush *rush)
{
	int i;
	int	j;

	i = -1;
	while (++i < rush->size)
	{
		j = -1;
		while (++j < rush->size)
		{
			if (check_nbr(rush->map_origin, i, j))
				get_new_size(rush, rush->map_modif[i - 1][j],
						rush->map_modif[i][j - 1],
						rush->map_modif[i - 1][j - 1]);
			else
				rush->map_modif[i][j] = 1;
		}
	}
	place_camp(rush, rush->map_origin, rush->c);
	ft_strdel_2d(rush->map_origin, rush->size, 1);
	ft_strdel_2d(rush->map_modif, rush->size, 0);
}