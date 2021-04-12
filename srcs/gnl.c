#include "rush01.h"

char	*gnl(int len)
{
	int		ret;
	char	*line;

	line = (char *)malloc(len + 1);
	if (!(*line))
		return (NULL);
	*line = '\0';
	ret = read(STDIN_FILENO, line, len + 1);
	line[len] = 0;
	return (line);
}
