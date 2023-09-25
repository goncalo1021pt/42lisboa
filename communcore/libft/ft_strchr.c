#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		ctd;
	char	*str;

	str = (char *)s;
	ctd = 0;
	while (s[ctd])
	{
		if (s[ctd] == c)
			return (str + ctd);
		ctd++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char c[11] = "test string";

	printf("%s\n", (char *)strchr(c, 's'));
	printf("%s\n", (char *)ft_strchr(c, 's'));
	return (0);
} */