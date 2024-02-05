#include "../includes/philosophers.h"

t_bool	is_in_array(char *str, char c)
{
	int ctd;

	while (*str)
	{
		if (*str == c)
			return (TRUE);
		str++;
	}
	return (FALSE);
}

long	ft_atol(char *nptr)
{
	int		ctd;
	int		signal;
	long	result;

	ctd = 0;
	signal = 1;
	result = 0;
	while (is_in_array(SPACE_LIST, nptr[ctd]))
		ctd++;
	if (nptr[ctd] == '+' || nptr[ctd] == '-')
		if (nptr[ctd++] == '-')
			signal = -signal;
	while (nptr[ctd] <= '9' && nptr[ctd] >= '0' && result < INT_MAX)
	{
		result *= 10;
		result += nptr[ctd++] - '0';
	}
	return (signal * result);
}
