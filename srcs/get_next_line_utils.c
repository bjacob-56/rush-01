#include "rush01.h"

int	glen(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}

void	gnl_free(char **str)
{
	free(*str);
	*str = NULL;
}
