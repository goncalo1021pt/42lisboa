#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ctd;
	size_t	src_len;

	ctd = 0;
	while (ctd < size - 1 && src[ctd] != '\0')
	{
		dest[ctd] = src[ctd];
		ctd++;
	}
	if (size > 0)
		dest[ctd] = '\0';
	src_len = 0;
	while (src[src_len])
		src_len++;
	return (ctd);
}

/* #include <stdio.h>
int main() {
    char dest[10];
    char *src = "Hello World!";

    size_t result = ft_strlcpy(dest, src, sizeof(dest));

    printf("Copied string: %s\n", dest);
    printf("Total characters copied: %ld\n", result);

    return 0;
} */