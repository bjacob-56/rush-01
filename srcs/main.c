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
	int		i;

	init_struct(&r);
	r.size = ft_atoi_read();
	read(0, &buffer, 2);
	r.c = buffer[0];
	r.map_origin = (char **)malloc(sizeof(char *) * r.size);
	r.map_modif = (int **)malloc(sizeof(int *) * r.size);
	i = -1;
	while (++i < r.size)
	{
		get_next_line(r.map_origin + i, r.size);
		r.map_modif[i] = (int *)malloc(sizeof(int) * r.size);
	}
	algo(&r);
	return (0);
}
