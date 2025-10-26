/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:29:46 by gfontao-          #+#    #+#             */
/*   Updated: 2025/03/05 23:42:34 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	ctd2;

	ctd2 = 0;
	while (str[ctd2] != '\0')
		ctd2++;
	return (ctd2);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	ctd;
	unsigned int	ctd2;

	ctd = 0;
	ctd2 = 0;
	if (*to_find == '\0')
		return (str);
	while (str[ctd])
	{
		if (str[ctd] == to_find[ctd2])
		{
			while (to_find[ctd2])
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

char	*teste(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == to_find[j])
		{
			j++;
		}
		i++;
	}
	return (0);
}


int main()
{
	char a[] = "testing my string";
	char b[] = "";

	printf("original: %s\n", strstr(a, b));
	printf("my test: %s\n", ft_strstr(a, b));
	printf("kita: %s", teste(a, b));
	return(0);
}
