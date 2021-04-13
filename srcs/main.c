#include "rush01.h"

void	init_struct(t_rush *t)
{
	t->c = 0;
	t->i_max = 0;
	t->j_max = 0;
	t->map_modif = NULL;
	t->map_origin = NULL;
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
	r.map_origin = (char *)malloc(sizeof(char *) * map_len);
	r.map_modif = (int *)malloc(sizeof(int *) * map_len);
	read(STDIN_FILENO, r.map_origin, map_len + r.size);
	algo(&r);
	return (0);
}
