#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *out;

	
	out = malloc(nmemb * size);
	
	return out;
}
