#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			ctd;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	ctd = 0;
	while (ctd < n)
	{
		d[ctd] = s[ctd];
		ctd++;
	}
	return (dest);
}

/* #include <stdio.h>
int main()
{
	char c[11] = "test string";

	ft_memmove(c, "hello", 5);
	printf("%s\n", c);
	return 0;
} */