/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:29:46 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/11 10:20:12 by gfontao-         ###   ########.fr       */
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

int main()
{
	char a[] = "testing my string";
	char b[] = "my";

	printf("%s", ft_strstr(a, b));
	return(0);
}
