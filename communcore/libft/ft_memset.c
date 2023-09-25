#include "libft.h"

//This function will set n number of bytes of the string str to the ascci char c
//It returns a pointer to the start of str

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*mem;
	size_t			ctd;

	ctd = 0;
	mem = str;
	while (ctd < n)
		mem[ctd++] = c;
	return (str);
}
