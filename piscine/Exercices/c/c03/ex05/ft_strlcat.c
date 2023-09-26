/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:49:23 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/14 22:00:32 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
		ctd++;
	return (ctd);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	ctd;
	unsigned int	sstr;
	unsigned int	sdest;

	ctd = 0;
	sdest = ft_strlen(dest);
	sstr = ft_strlen(src);
	if (size < 1)
		return (sstr + size);
	while (src[ctd] && (ctd + sdest) < size -1)
	{
		dest[ctd + sdest] = src[ctd];
		ctd++;
	}
	dest[ctd + sdest] = '\0';
	if (size < sdest)
		return (sstr + size);
	else
		return (sdest + sstr);
}

/* int main()
{
	char a[] = "testing";
	char b[50] = "hello ";
	int aux = ft_strlcat(b,a,14);
	printf("return: %d\n %s",aux , b);
	return(0);
} */