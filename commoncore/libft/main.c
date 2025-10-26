#include "libft.h"
#include "ft_malloc.h"
int main()
{
	char *str;

	str = malloc(10);
	if (str == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	free(str);
	str = malloc(10);
	if (str == NULL)
	{
		printf("Memory allocation failed\n");
		return (2);
	}
	free(str);
	str = malloc(10);
	if (str == NULL)
	{
		printf("Memory allocation failed\n");
		return (3);
	}
	free(str);
	str = malloc(10);
	if (str == NULL)
	{
		printf("Memory allocation failed\n");
		return (4);
	}
	free(str);
	return (0);
}
