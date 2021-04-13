#include "rush01.h"

static int	glen(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}

static int	check_kept(char *to_keep, char **line)
{
	char	*kept;
	char	*tmp;
	int		in_line;

	kept = to_keep;
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
		ret = read(0, buf, len +1);
		buf[ret] = '\0';
		if (ret < 1)
			in_line = ret;
		else
			in_line = clean_buf(&buf, to_keep, line, ret);
		free(buf);
	}
	return (in_line);
}

int	get_next_line(char **line, int len)
{
	static char	*to_keep;
	int			in_line;

	*line = (char *)malloc(len + 1);
	**line = '\0';
	in_line = 2;
	if (to_keep)
		in_line = check_kept(to_keep, line);
	else
	{
		to_keep = (char *)malloc(len + 2);
		*to_keep = '\0';
	}
	in_line = gnl_algo(in_line, len, &to_keep, line);
	if (!in_line)
		free(to_keep);
	return (in_line);
}
