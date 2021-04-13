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

static void	check_and_manage_nbr(t_rush *r, int i, int j, int s)
{
	if (i != 0 && j != 0
		&& r->map_o[i * (s + 1) + j] == r->map_o[(i - 1) * (s + 1) + j]
		&& r->map_o[i * (s + 1) + j] == r->map_o[i * (s + 1) + j - 1]
		&& r->map_o[i * (s + 1) + j] == r->map_o[(i - 1) * (s + 1) + j - 1])
	{
		if (r->map_m[(i - 1) * (s + 1) + j] <= r->map_m[i * (s + 1) + j - 1] &&
			r->map_m[(i - 1) * (s + 1) + j] <= r->map_m[(i - 1) * (s + 1) +
			j - 1])
			r->map_m[i * (s + 1) + j] = r->map_m[(i - 1) * (s + 1) + j] + 1;
		else if (r->map_m[i * (s + 1) + j - 1] <= r->map_m[(i - 1) *
			(s + 1) + j - 1])
			r->map_m[i * (s + 1) + j] = r->map_m[i * (s + 1) + j - 1] + 1;
		else
			r->map_m[i * (s + 1) + j] = r->map_m[(i - 1) * (s + 1) + j - 1]
			+ 1;
		if (r->map_m[i * (s + 1) + j] > r->max)
		{
			r->max = r->map_m[i * (s + 1) + j];
			r->i_max = i;
			r->j_max = j;
		}
	}
	else
		r->map_m[i * (s + 1) + j] = 1;
}

// static int	check_nbr(char **map_o, int i, int j)
// {
// 	char	height;

// 	height = map_o[i][j];
// 	return (i != 0 && j != 0
// 		&& height == map_o[i - 1][j]
// 		&& height == map_o[i][j - 1]
// 		&& height == map_o[i - 1][j - 1]);
// }

// static void	get_new_size(t_rush *rush, int i, int j)
// {
// 	int	val[3];

// 	val[1] = rush->map_m[i - 1][j];
// 	val[2] = rush->map_m[i][j - 1];
// 	val[0] = rush->map_m[i - 1][j - 1];
// 	if (val[1] <= val[2] && val[1] <= val[0])
// 		rush->map_m[i][j] = val[1] + 1;
// 	else if (val[2] <= val[0])
// 		rush->map_m[i][j] = val[2] + 1;
// 	else
// 		rush->map_m[i][j] = val[0] + 1;
// 	if (rush->map_m[i][j] > rush->max)
// 	{
// 		rush->max = rush->map_m[i][j];
// 		rush->i_max = i;
// 		rush->j_max = j;
// 	}
// }

// static void	get_new_size(t_rush *rush, int i, int j)
// {
// 	if (rush->map_m[i - 1][j] <= rush->map_m[i][j - 1] &&
// 		rush->map_m[i - 1][j] <= rush->map_m[i - 1][j - 1])
// 		rush->map_m[i][j] = rush->map_m[i - 1][j] + 1;
// 	else if (rush->map_m[i][j - 1] <= rush->map_m[i - 1][j - 1])
// 		rush->map_m[i][j] = rush->map_m[i][j - 1] + 1;
// 	else
// 		rush->map_m[i][j] = rush->map_m[i][j - 1] + 1;
// 	if (rush->map_m[i][j] > rush->max)
// 	{
// 		rush->max = rush->map_m[i][j];
// 		rush->i_max = i;
// 		rush->j_max = j;
// 	}
// }

static	void	place_camp(t_rush *rush, char *map_o, char c, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rush->max)
	{
		j = -1;
		while (++j < rush->max)
			map_o[(rush->i_max - i) * (size + 1) + rush->j_max - j] = c;
	}
}

void	algo(t_rush *rush)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rush->size)
	{
		j = -1;
		while (++j < rush->size)
			check_and_manage_nbr(rush, i, j, rush->size);
	}
	place_camp(rush, rush->map_o, rush->c, rush->size);
	write(1, rush->map_o, rush->size * (rush->size + 1));
	free(rush->map_o);
	free(rush->map_m);
}
