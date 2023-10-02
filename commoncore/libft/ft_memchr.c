/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:37 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/30 20:43:01 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function will search for the char c in the string str
//It return a poiter to the first ocurrence of c in str
//If c is not in str it will return NULL

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				ctd;
	unsigned char		*s;

	ctd = 0;
	s = (unsigned char *)str;
	while (ctd < n)
	{
		if (s[ctd] == (unsigned char)c)
			return ((void *)s + ctd);
		ctd++;
	}
	return (NULL);
}

/* #include <stdio.h>
int	main(void)
{
	char c[11] = "test string";

	printf("%s\n", (char *)ft_memchr(c, 's', 5));
	return (0);
} */