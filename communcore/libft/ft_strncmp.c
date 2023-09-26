#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ctd;

	ctd = 0;
	while (s1[ctd] && s2[ctd] && ctd < n - 1)
	{
		if (s1[ctd] != s2[ctd])
			return (s1[ctd] - s2[ctd]);
		ctd++;
	}
	return (s1[ctd] - s2[ctd]);
}

/* #include <stdio.h>
int main()
{
	printf("%d\n", ft_strncmp("test1", "test1", 5));
	return 0;
} */