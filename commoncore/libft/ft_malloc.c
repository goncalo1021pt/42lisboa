#include "ft_malloc.h"

void	*ft_malloc(size_t size)
{
	static int	allocations = 0;	
	void		*ptr;

	if (allocations == ALLOC_LIMIT)
		return (NULL);
	#undef malloc
	ptr = malloc(size);
	#define malloc(size) ft_malloc(size)
	if (ptr)
		allocations++;
	return (ptr);
}
