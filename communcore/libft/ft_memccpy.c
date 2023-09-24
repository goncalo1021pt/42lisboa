#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*mem;
	const unsigned char	*old;
	size_t				ctd;

	ctd = 0;
	mem = dest;
	old = src;
	while (ctd < n)
	{
		*mem = old[ctd];
		if (old[ctd] == c)
			return (mem);
		mem++;
		ctd++;
	}
	return (NULL);
}
