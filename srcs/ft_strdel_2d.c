#include "rush01.h"

char	**ft_strdel_2d_char(char **t, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		write(1, t[i], size + 1);
		free(t[i]);
		t[i] = NULL;
	}
	free(t);
	return (NULL);
}

int	**ft_strdel_2d_int(int **t, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		free(t[i]);
		t[i] = NULL;
	}
	free(t);
	return (NULL);
}
