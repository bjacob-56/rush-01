#include "rush01.h"

static void	set_new_max(t_max *data_max, int i, int j)
{
	data_max->i = i;
	data_max->j = j;
	data_max->max++;
}

static void	check_and_manage_nbr(char **o, int *m, t_max *data_max,
	int s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s)
	{
		j = -1;
		while (++j < s)
		{
			if (i != 0 && j != 0 && o[i][j] == o[i - 1][j] &&
				o[i][j] == o[i][j - 1] && o[i][j] == o[i - 1][j - 1])
			{
				m[i * s + j] = m[(i - 1) *s + j] + 1;
				if (m[i * s + j] > m[i * s + j - 1] + 1)
					m[i * s + j] = m[i * s + j - 1] + 1;
				if (m[i * s + j] > m[(i - 1) *s + j - 1] + 1)
					m[i * s + j] = m[(i - 1) *s + j - 1] + 1;
				if (m[i * s + j] > data_max->max)
					set_new_max(data_max, i, j);
			}
			else
				m[i * s + j] = 1;
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

static void	algo(char **map_o, char c, int size)
{
	t_max	data_max;
	int		i;
	int		*map_m;

	map_m = malloc(4 * size * size);
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
	}
	free(map_o);
	free(map_m);
}

int	main(void)
{
	int		size;
	char	buffer[2];
	char	**map_o;
	int		i;

	size = 0;
	read(0, buffer, 1);
	while (buffer[0] != '\n')
	{
		size = 10 * size + (buffer[0] - '0');
		read(0, buffer, 1);
	}
	read(0, &buffer, 2);
	map_o = malloc(sizeof(char *) * size);
	i = -1;
	while (++i < size)
		get_next_line(map_o + i, size);
	algo(map_o, buffer[0], size);
	return (0);
}
