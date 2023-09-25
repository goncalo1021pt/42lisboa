#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			ctd;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	ctd = 0;
	while (ctd < n)
	{
		if (c1[ctd] != c2[ctd])
			return (c1[ctd] - c2[ctd]);
		ctd++;
	}
	return (0);
}
/* #include <string.h>
#include <stdio.h>
int	main(void)
{
	char c[11] = "test string";
	int size = 10;

	printf("%d\n", ft_memcmp(c, "test", size));
	printf("%d\n", memcmp(c, "test", size));
	
	return (0);
} */