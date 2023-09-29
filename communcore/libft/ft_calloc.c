/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:01:12 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/29 15:00:51 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;

	out = malloc((nmemb * size) + 1);
	if (out != NULL)
		ft_memset(out, 0, size);
	return (out);
}

/* #include <stdio.h>
int	main(void)
{
	int nmemb = 5;

	int *myAlloc = (int *)ft_calloc(nmemb, sizeof(int));
	if (myAlloc == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	for (int ctd = 0; ctd < nmemb; ctd++)
	{
		printf("%d ", ctd);
		if (myAlloc[ctd] != 0)
		{
			printf("Error: Allocated memory is not initialized to zero.\n");
			return (1);
		}
	}
	free(myAlloc);
	return (0);
} */