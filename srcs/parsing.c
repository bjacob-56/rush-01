#include "rush01.h"

static int	error_msg(void)
{
	write(STDIN_FILENO, "GNL FAILED", ft_strlen("GNL FAILED"));
	return (-1);
}

static int	fill_map(t_rush *r)
{
	int		i;
	int		ret;
	char	*reading;

	i = -1;
	while (++i < r->size)
	{
		ret = get_next_line(STDIN_FILENO, &reading);
		if (ret == -1)
			return (error_msg());
		r->map_origin[i] = reading;
		r->map_modif[i] = (int *)malloc(sizeof(int) * r->size);
	}
	return (0);
}

int	pars(t_rush *r)
{
	char	*reading;

	if (get_next_line(STDIN_FILENO, &reading) == -1)
		return (error_msg());
	r->size = ft_atoi(reading);
	free(reading);
	if (get_next_line(STDIN_FILENO, &reading) == -1)
		return (error_msg());
	r->c = reading[0];
	free(reading);
	r->map_origin = (char **)malloc(sizeof(char *) * r->size);
	r->map_modif = (int **)malloc(sizeof(int *) * r->size);
	return (fill_map(r));
}
