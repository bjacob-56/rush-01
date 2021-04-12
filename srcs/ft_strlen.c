#include "rush01.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (*s++)
			i++;
	}
	return (i);
}
