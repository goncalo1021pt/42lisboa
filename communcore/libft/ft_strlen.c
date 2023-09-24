#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd])
		ctd++;
	return (ctd);
}
