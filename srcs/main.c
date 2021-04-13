#include "rush01.h"

void	init_struct(t_rush *t)
{
	t->c = 0;
	t->i_max = 0;
	t->j_max = 0;
	t->map_m = NULL;
	t->map_o = NULL;
	t->max = 1;
	t->size = 0;
}

int	main(void)
{
	t_rush	r;
	char	buffer[2];
	int		map_len;

	init_struct(&r);
	r.size = ft_atoi_read();
	read(0, &buffer, 2);
	map_len = r.size * r.size;
	r.c = buffer[0];
	r.map_o = (char *)malloc(map_len + r.size + 1);
	r.map_m = (int *)malloc(sizeof(int) * map_len);
	read(STDIN_FILENO, r.map_o, map_len + r.size);
	algo(&r);
	return (0);
}
