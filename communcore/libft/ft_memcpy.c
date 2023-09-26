#include "libft.h"

//This functions copies n bytes from src into dest
//It doesn't take care of overlaping memory
//It returns a pointer to n the start of dest

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
