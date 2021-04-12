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
	char	height;

	height = map_origin[i][j];
	return (i != 0 && j != 0
		&& height == map_origin[i - 1][j]
		&& height == map_origin[i][j - 1]
		&& height == map_origin[i - 1][j - 1]);
}

static void	get_new_size(t_rush *rush, int i, int j)
{
	int	val;
	int	val1;
	int	val2;
	int	val3;

	val1 = rush->map_modif[i - 1][j];
	val2 = rush->map_modif[i][j - 1];
	val3 = rush->map_modif[i - 1][j - 1];
	if (val1 <= val2)
	{
		if (val1 <= val3)
			val = val1 + 1;
		val = val3 + 1;
	}
	else if (val2 <= val3)
		val = val2 + 1;
	else
		val = val3 + 1;
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

//////////////////////////////////////
//////////////////////////////////////
// static char *to_up_print(char *str, int size)
// {
// 	int i;

// 	i = -1;
// 	while (++i < size)
// 		str[i] = str[i] + '0';
// 	return str;
// }

// char	**ft_strdel_2d_bis(char **t, int size, int print)
// {
// 	int		i;
// 	char	c;

// 	i = -1;
// 	c = '\n';
// 	while (++i < size)
// 	{
// 		if (print)
// 		{
// 			write(1, to_up_print(t[i], size), size);
// 			write(1, &c, 1);
// 		}
// 		free(t[i]);
// 		t[i] = NULL;
// 	}
// 	free(t);
// 	return (NULL);
// }
//////////////////////////////////////
//////////////////////////////////////

void	algo(t_rush *rush)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rush->size)
	{
		j = -1;
		while (++j < rush->size)
		{
			if (check_nbr(rush->map_origin, i, j))
				get_new_size(rush, i, j);
			else
				rush->map_modif[i][j] = 1;
		}
	}
	place_camp(rush, rush->map_origin, rush->c);
	ft_strdel_2d_char(rush->map_origin, rush->size, 1);
	ft_strdel_2d_int(rush->map_modif, rush->size);
	// ft_strdel_2d(rush->map_origin, rush->size, 0);
	// ft_strdel_2d_bis(rush->map_modif, rush->size, 1);
}
