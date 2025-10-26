#ifndef FT_MALLOC_H

# include <stdlib.h>
void	*ft_malloc(size_t size);

# define malloc(size) ft_malloc(size)
# ifndef ALLOC_LIMIT
#  define ALLOC_LIMIT 2
# endif

#endif