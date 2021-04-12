#include "rush01.h"

static int	glen(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

static char	*grea(char *pt, int size)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(size + 1);
	while (size-- > 1 && pt[i])
	{
		new[i] = pt[i];
		i++;
	}
	new[i++] = 0;
	new[i] = 0;
	free(pt);
	pt = NULL;
	return (new);
}

int	get_next_line(char **line)
{
	char	buf[1];
	int		l;
	int		ret;

	*line = malloc(1);
	**line = 0;
	l = 2;
	while (l > 1)
	{
		*line = grea(*line, glen(*line) + 1);
		ret = read(0, buf, 1);
		if (ret)
		{
			if (buf[0] == '\n')
				l = 1;
			else
				(*line)[glen(*line)] = buf[0];
		}
		else
		{
			l =0;
		}
	}
	return (l);
}
