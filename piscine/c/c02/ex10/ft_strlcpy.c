/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:56:04 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/05 11:32:14 by gfontao-         ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	ctd;

	src_len = ft_strlen(src);
	if (size == 0)
	{
		return (src_len);
	}
	ctd = 0;
	while (ctd < size - 1 && src[ctd] != '\0')
	{
		dest[ctd] = src[ctd];
		ctd++;
	}
	dest[ctd] = '\0';
	return (src_len);
}

/*int main()
{
    char source[] = "Hello, World!";
    char destination[15]; 
    unsigned int copied = ft_strlcpy(destination, source, sizeof(destination));

    printf("return value  %u\n", copied);
    printf("copied string : %s\n", destination);

    return 0;
}*/
