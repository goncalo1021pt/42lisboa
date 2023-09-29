/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:02:15 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/29 14:22:55 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ctd;
	size_t	src_len;

	ctd = 0;
	while (ctd < size - 1 && src[ctd] != '\0')
	{
		dest[ctd] = src[ctd];
		ctd++;
	}
	if (size > 0)
		dest[ctd] = '\0';
	src_len = 0;
	while (src[src_len])
		src_len++;
	return (src_len);
}

/* #include <stdio.h>
int main() {
    char dest[10];
    char *src = "Hello World!";

    size_t result = ft_strlcpy(dest, src, sizeof(dest));

    printf("Copied string: %s\n", dest);
    printf("Total characters copied: %ld\n", result);

    return 0;
} */