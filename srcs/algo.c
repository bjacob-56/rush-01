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

static void	set_new_max(t_max *data_max, int i, int j)
{
	data_max->i = i;
	data_max->j = j;
	data_max->max++;
}

static void	check_and_manage_nbr(char **o, int **m, t_max *data_max,
	int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (i != 0 && j != 0 && o[i][j] == o[i - 1][j] &&
				o[i][j] == o[i][j - 1] && o[i][j] == o[i - 1][j - 1])
			{
				m[i][j] = m[i - 1][j] + 1;
				if (m[i][j] > m[i][j - 1] + 1)
					m[i][j] = m[i][j - 1] + 1;
				if (m[i][j] > m[i - 1][j - 1] + 1)
					m[i][j] = m[i - 1][j - 1] + 1;
				if (m[i][j] > data_max->max)
					set_new_max(data_max, i, j);
			}
			else
				m[i][j] = 1;
		}
	}
}

static void	place_camp(char **map_o, t_max *data_max, char c, int max)
{
	int	i;
	int	j;
	int	i_max;
	int	j_max;
	
	i_max = data_max->i;
	j_max = data_max->j;
	i = -1;
	while (++i < max)
	{
		j = -1;
		while (++j < max)
			map_o[i_max - i][j_max - j] = c;
	}
}

void	algo(char **map_o, int **map_m, char c, int size)
{
	t_max	data_max;
	int		i;

	data_max.i = 0;
	data_max.j = 0;
	data_max.max = 1;
	check_and_manage_nbr(map_o, map_m, &data_max, size);
	place_camp(map_o, &data_max, c, data_max.max);
	i = -1;
	while (++i < size)
	{
		write(1, map_o[i], size + 1);
		free(map_o[i]);
		free(map_m[i]);
	}
	free(map_o);
	free(map_m);
}
