/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:12:56 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/11 14:13:17 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
		ctd++;
	return (ctd);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	ctd;

	ctd = 0;
	while (src[ctd] != '\0')
	{
		dest[ctd] = src[ctd];
		ctd++;
	}
	dest[ctd] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*str;

	str = (char *)malloc(ft_strlen(src) + 1);
	ft_strcpy(str, src);
	return (str);
}

/*int main(){
	char *str = "strdup test";
	char *newstr;

	newstr = ft_strdup(str);
	printf("%s\n", newstr);

	free(newstr);
	return 0;
}*/