#include "rush01.h"

char	**ft_strdel_2d(char **t)
{
	int	i;

	i = -1;
	while (t[++i])
		;
	while (i--)
	{
		free(t[i]);
		t[i] = NULL;
	}
	free(t);
	return (NULL);
}
