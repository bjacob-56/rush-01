#include "rush01.h"

static void	set_new_max(t_max *data_max, u_int16_t i, u_int16_t j)
{
	data_max->i = i;
	data_max->j = j;
	data_max->max++;
}

static void	check_and_manage_nbr(char *o, u_int16_t *m, t_max *data_max,
	int s)
{
	u_int16_t	i;
	u_int16_t	j;
	u_int32_t	sum;

	i = -1;
	while (++i < s)
	{
		j = -1;
		while (++j < s)
		{
			sum = i * s + j;
			m[sum] = 1;
			if (i != 0 && j != 0 && o[sum + i] == o[sum + i - s - 1] && o[sum
					+ i] == o[sum + i - 1] && o[sum + i] == o[sum + i - s - 2])
			{
				m[sum] = m[sum - s];
				if (m[sum] > m[sum - 1])
					m[sum] = m[sum - 1];
				if (m[sum] > m[sum - s - 1])
					m[sum] = m[sum - s - 1];
				if (++m[sum] > data_max->max)
					set_new_max(data_max, i, j);
			}
		}
	}
}

static void	algo(char *map_o, char c, u_int16_t size)
{
	t_max		data_max;
	u_int16_t	i;
	u_int16_t	j;
	u_int16_t	*map_m;

	map_m = malloc(4 * size * size);
	data_max.i = 0;
	data_max.j = 0;
	data_max.max = 1;
	check_and_manage_nbr(map_o, map_m, &data_max, size);
	i = -1;
	while (++i < data_max.max)
	{
		j = -1;
		while (++j < data_max.max)
			map_o[(data_max.i - i) *(size + 1) + data_max.j - j] = c;
	}
	write(1, map_o, size * (size + 1));
	free(map_o);
	free(map_m);
}

int	main(void)
{
	u_int16_t	size;
	char		buffer[2];
	char		*map_o;

	size = 0;
	read(0, buffer, 1);
	while (buffer[0] != '\n')
	{
		size = 10 * size + (buffer[0] - '0');
		read(0, buffer, 1);
	}
	read(0, buffer, 2);
	map_o = malloc(sizeof(char) * (size * (size + 1) + 1));
	read(0, map_o, size * (size + 1));
	algo(map_o, buffer[0], size);
	return (0);
}
