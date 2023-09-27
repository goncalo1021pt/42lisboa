/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:49 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/27 14:01:50 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This functions copies n bytes from src into dest
//It takes care of overlaping memory
//It returns a pointer to n the start of dest

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	ctd;

	if (dest == src)
		return (dest);
	if (src < dest && dest < src + n)
	{
		ctd = n - 1;
		while (ctd > 0)
		{
			((unsigned char *)dest)[ctd] = ((unsigned char *)src)[ctd];
			ctd--;
		}
	}
	else
	{
		ctd = 0;
		while (ctd < n)
		{
			((unsigned char *)dest)[ctd] = ((unsigned char *)src)[ctd];
			ctd++;
		}
	}
	return (dest);
}

/* #include <stdio.h>
int	main(void)
{
	char c[11] = "test string";

	ft_memmove(c, "hello", 5);
	printf("%s\n", c);
	return (0);
}  */