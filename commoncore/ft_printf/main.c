#include "ft_printf.h"
#include <stdio.h>


int main()
{
	printf(" :%d\n", ft_printf("hi %c %d %i %x %X",'c',0,10,10,10));
	printf(" :%d\n", printf("hi %c %d %i %x %X",'c',0,10,10,10));
}
