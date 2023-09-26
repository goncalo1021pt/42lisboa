/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:21:49 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/19 18:04:46 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	ctd;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof(int));
	if (range == 0)
		return (-1); 
	ctd = 0;
	while (ctd < (max - min))
	{
		(*range)[ctd] = min + ctd;
		ctd++;
	}
	return (max - min);
}

int main ()
{
	int *test;
	int ctd = 0;
	int size;

	size = ft_ultimate_range(&test,-4,10);
	printf("size is = %d\n", size);
	while (ctd < 14)
	{
		printf("%d ",test[ctd]);
		ctd++;
	}
	free (test);
}