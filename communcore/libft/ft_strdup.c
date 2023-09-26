#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*str;

	str = (char *)malloc(ft_strlen(src) + 1);
	if (str == NULL)
		return (str);
	ft_strcpy(str, src);
	return (str);
}
