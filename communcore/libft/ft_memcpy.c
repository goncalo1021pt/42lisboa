#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*mem;
	const unsigned char	*old;
	size_t				ctd;

	ctd = 0;
	mem = dest;
	old = src;
	while (ctd < n)
	{
		mem[ctd] = old[ctd];
		ctd++;
	}
	return (dest);
}
