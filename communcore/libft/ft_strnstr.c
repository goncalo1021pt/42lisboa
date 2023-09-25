#include "libft.h"

char 	strnstr (const char *str, const char *to_find, size_t len)
{
	unsigned int	ctd;
	unsigned int	ctd2;

	ctd = 0;
	ctd2 = 0;
	if (*to_find == '\0')
		return (str);
	while (str[ctd] && ctd < len)
	{
		if (str[ctd] == to_find[ctd2])
		{
			while (to_find[ctd2] && (ctd + ctd2) >)
			{
				if (to_find[ctd2] != str[ctd + ctd2])
					break ;
				ctd2++;
			}
			if (ctd2 == (unsigned int)ft_strlen(to_find))
				return (str + ctd);
			ctd2 = 0;
		}
		ctd++;
	}
	return (0);
}

/* int main()
{
	char a[] = "testing my string";
	char b[] = "my";

	printf("%s", ft_strstr(a, b));
	return(0);
} */