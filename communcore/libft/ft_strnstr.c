#include "libft.h"

//This function searches n bytes of the str for the string to find
//It returns a pointer to the found string or null if there wasn't 1

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	ctd;
	size_t	ctd2;

	ctd = 0;
	ctd2 = 0;
	if (*to_find == '\0')
		return (str);
	while (str[ctd] && ctd < len)
	{
		if (str[ctd] == to_find[ctd2])
		{
			while (to_find[ctd2] && (ctd + ctd2) < len)
			{
				if (to_find[ctd2] != str[ctd + ctd2])
					break ;
				ctd2++;
			}
			if (ctd2 == ft_strlen(to_find))
				return (str + ctd);
			ctd2 = 0;
		}
		ctd++;
	}
	return (0);
}

/* #include <stdio.h>
int	main(void)
{
	char a[] = "testing my string";
	char b[] = "my";

	printf("%s", ft_strnstr(a, b, 9));
	return(0);
} */