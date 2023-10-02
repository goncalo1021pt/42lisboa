/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:33 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/27 14:01:34 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This functions copies n bytes from src into dest
//Stops after finding c
//It returns a pointer to n the start of dest

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*mem;
	const unsigned char	*old;
	size_t				ctd;

	ctd = 0;
	mem = dest;
	old = src;
	while (ctd < n)
	{
		*mem = old[ctd];
		if (old[ctd] == c)
			return (mem);
		mem++;
		ctd++;
	}
	return (NULL);
}

/* #include <stdio.h>
int	main(void)
{
	char c[11] = "test string";

	ft_memmove(c, "hello", 5);
	printf("%s\n", c);
	return (0);
}  */