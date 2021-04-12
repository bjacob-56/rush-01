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
	char	*reading;
	int		i;
	int		ret;

	init_struct(&r);
	get_next_line(STDIN_FILENO, &reading);
	r.size = ft_atoi(reading);
	free(reading);
	get_next_line(STDIN_FILENO, &reading);
	r.c = reading[0];
	free(reading);
	r.map_origin = (char **)malloc(sizeof(char *) * r.size);
	r.map_modif = (int **)malloc(sizeof(int *) * r.size);
	i = -1;
	while (++i < r.size)
	{
		ret = get_next_line(STDIN_FILENO, &reading);
		r.map_origin[i] = reading;
		r.map_modif[i] = (int *)malloc(sizeof(int) * r.size);
	}
	algo(&r);
	return (0);
}
