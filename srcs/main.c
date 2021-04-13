#include "rush01.h"

static void	init_maps(char **map_o, int **map_m, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		get_next_line(map_o + i, size);
		map_m[i] = malloc(4 * size);
	}
}

int	main(void)
{
	int		size;
	char	buffer[2];
	char	**map_o;
	int		**map_m;

	size = 0;
	read(0, buffer, 1);
	while (buffer[0] != '\n')
	{
		size = 10 * size + (buffer[0] - '0');
		read(0, buffer, 1);
	}
	read(0, &buffer, 2);
	map_o = malloc(sizeof(char *) * size);
	map_m = malloc(sizeof(int *) * size);
	init_maps(map_o, map_m, size);
	algo(map_o, map_m, buffer[0], size);
	return (0);
}
