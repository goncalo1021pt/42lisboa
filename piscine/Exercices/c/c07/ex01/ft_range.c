/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:23:07 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/12 15:26:32 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*num;
	int	ctd;

	if (min >= max)
		return (0);
	num = (int *) malloc((max - min) * sizeof(int));
	ctd = 0;
	while (ctd < (max - min))
	{
		num[ctd] = min + ctd;
		ctd++;
	}
	return (num);
}

/*int main ()
{
	int *test;
	int ctd = 0;

	test = ft_range(-4,10);
	while (ctd < 14)
	{
		printf("%d ",test[ctd]);
		ctd++;
	}
	free (test);
}*/