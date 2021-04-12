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
	ret = get_next_line(STDIN_FILENO, &reading) == -1;
	while (ret)
	{
		if (ret == -1)
			return (error_msg());
		r->map_origin[++i] = reading;
		r->map_modif[i] = ft_strdup(reading);
	}
	return (0);
}

int	pars(t_rush *r)
{
	char	*reading;

	if (get_next_line(STDIN_FILENO, &reading) == -1)
		return (error_msg());
	r->size = ft_atoi(reading);
	if (get_next_line(STDIN_FILENO, &reading) == -1)
		return (error_msg());
	r->c = reading[0];
	r->map_origin = (char **)malloc(sizeof(char *) * r->size);
	r->map_modif = (char **)malloc(sizeof(char *) * r->size);
	return (fill_map(r));
}
