#include "libft.h"

// this functions returns the lenght of the string str

size_t	ft_strlen(const char *str)
{
	size_t	ctd;

	ctd = 0;
	while (str[ctd])
		ctd++;
	return (ctd);
}
