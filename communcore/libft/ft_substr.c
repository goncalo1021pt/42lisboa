#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	ctd;
	char			*out;

	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	ctd = 0;
	while (ctd < len)
	{
		out[ctd] = s[start + ctd];
		ctd++;
	}
	out[ctd] = '\0';
	return (out);
}

/* #include <stdio.h>
int main()
{
	char *test;

	test = ft_substr("test string", 5, 6);
	printf("%s\n", test);
	free(test);
	return (0);
} */