#include "rush01.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*d;

	d = dst;
	while (len-- > 0)
	{
		if (*src)
			*d++ = *src++;
		else
			*d++ = '\0';
	}
	return (dst);
}
