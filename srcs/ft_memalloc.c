#include "rush01.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*tmp;

	mem = (void *)malloc(size);
	if (!mem)
		return (NULL);
	tmp = mem;
	while (size--)
		*tmp++ = 0;
	return (mem);
}
