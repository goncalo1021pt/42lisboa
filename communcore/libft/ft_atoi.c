#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	ctd;
	int	signal;
	int	result;

	ctd = 0;
	signal = 1;
	while (nptr[ctd] == ' ' || (nptr[ctd] >= 9 && nptr[ctd] <= 13))
		ctd++;
	if (nptr[ctd] == '+' || nptr[ctd] == '-')
	{
		if (nptr[ctd] == '-')
		{
			signal = -signal;
		}
		ctd++;
	}
	while (nptr[ctd] <= '9' && nptr[ctd] >= '0')
	{
		result *= 10;
		result += nptr[ctd] - '0';
		ctd++;
	}
	return (signal * result);
}

/* int main()
{
	printf("%d", ft_atoi("     -1234"));
} */