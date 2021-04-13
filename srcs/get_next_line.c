#include "rush01.h"

static char	*gnl_rea(char *ptr, int size)
{
	char	*nptr;
	int		i;

	nptr = (char *)malloc(sizeof(char) * size);
	if (!nptr)
	{
		gnl_free(&ptr);
		return (NULL);
	}
	i = 0;
	while (size-- > 1 && ptr[i])
	{
		nptr[i] = ptr[i];
		i++;
	}
	nptr[i] = '\0';
	gnl_free(&ptr);
	return (nptr);
}

static int	check_kept(char *to_keep, char **line)
{
	char	*kept;
	char	*tmp;
	int		in_line;

	kept = to_keep;
	// *line = gnl_rea(*line, glen(to_keep, '\n') + 1);
	// if (!(*line))
	// 	return (-1);
	tmp = *line;
	in_line = 2;
	while (*kept)
	{
		if (*kept == '\n' && in_line == 2)
		{
			in_line = 1;
			*tmp = '\0';
			kept++;
			tmp = to_keep;
		}
		*tmp++ = *kept++;
	}
	*tmp = '\0';
	return (in_line);
}

static int	clean_buf(char **buf, char **to_keep, char **line, int ret)
{
	char	*tmp;
	char	*buffer;
	int		in_line;

	in_line = 2;
	buffer = *buf;
	// *line = gnl_rea(*line, glen(*line, '\0') + ret + 1);
	// *to_keep = gnl_rea(*to_keep, glen(*to_keep, '\0') + ret + 1);
	if (!(*line) || !(*to_keep))
		return (-1);
	tmp = &(*line)[glen(*line, '\0')];
	while (ret--)
	{
		if (*buffer == '\n' && in_line == 2)
		{
			*tmp = '\0';
			buffer++;
			in_line = 1;
			tmp = *to_keep;
		}
		*tmp++ = *buffer++;
	}
	*tmp = '\0';
	return (in_line);
}

static int	gnl_algo(int in_line, int len, char **to_keep, char **line)
{
	int			ret;
	char		*buf;

	while (in_line > 1)
	{
		buf = (char *)malloc(sizeof(char) * (len +1 + 1));
		if (!buf)
			return (-1);
		ret = read(0, buf, len +1);
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (ret < 1)
			in_line = ret;
		else
			in_line = clean_buf(&buf, to_keep, line, ret);
		gnl_free(&buf);
	}
	*line = gnl_rea(*line, glen(*line, '\0') + 1);
	if (!(*line))
		return (-1);
	return (in_line);
}

int	get_next_line(char **line, int len)
{
	static char	*to_keep;
	int			in_line;

	*line = (char *)malloc(len + 1);
	if (!(*line))
		return (-1);
	**line = '\0';
	in_line = 2;
	if (to_keep)
		in_line = check_kept(to_keep, line);
	else
	{
		to_keep = (char *)malloc(len + 2);
		if (!to_keep)
			return (-1);
		*to_keep = '\0';
	}
	in_line = gnl_algo(in_line, len, &to_keep, line);
	if (in_line != 0 && in_line != 1)
		return (-1);
	if (!in_line)
		free(to_keep);
	return (in_line);
}
