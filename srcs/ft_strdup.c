#include "rush01.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		n;

	n = ft_strlen(s1);
	new = (char *)malloc(n + 1);
	if (!new)
		return (NULL);
	return (ft_strncpy(new, s1, n));
}
