/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:49 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/30 20:17:31 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This functions copies n bytes from src into dest
//It takes care of overlaping memory
//It returns a pointer to n the start of dest

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	ctd;

	ctd = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	if ((size_t)dest - (size_t)src < n)
	{
		ctd = (int)n - 1;
		while (ctd >= 0 && ctd < (int)n)
		{
			(((unsigned char *)dest)[ctd] = ((unsigned char *)src)[ctd]);
			ctd--;
		}
	}
	else
	{
		while (ctd < (int)n)
		{
			(((unsigned char *)dest)[ctd] = ((unsigned char *)src)[ctd]);
			ctd++;
		}
	}
	return (dest);
}

/*  #include <stdio.h>
int	main(void)
{
	char c[11] = "test string";

	ft_memmove(c, "hello", 5);
	printf("%s\n", c);
	return (0);
} */