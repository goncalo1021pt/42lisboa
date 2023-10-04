#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *test = "teste de string";
	char *test1 = "ola";
	ft_printf(":%d\n",ft_printf("%d %s %c %X %p %%", 10, "teste", 'c', 63, test1));
	printf(":%d\n",printf("%d %s %c %X %p %%", 10, "teste", 'c', 63, test1));
}