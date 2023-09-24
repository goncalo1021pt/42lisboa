#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*mem;
	size_t			ctd;

	ctd = 0;
	mem = str;
	while (ctd < n)
		mem[ctd++] = '\0';
}

/* #include <stdio.h>
int main(){
	char test[] = "testing string";
	
	printf("before function: %s\n", test);
	ft_bzero (test, 14);
	printf("after function: %s\n", test);
} */