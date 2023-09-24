#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	c1;
	size_t			ctd;

	ctd = 0;
	mem = str;
	c1 = c;
	while (ctd < n)
		mem[ctd++] = c1;
	return (str);
}
