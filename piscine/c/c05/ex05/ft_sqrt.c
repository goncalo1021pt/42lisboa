/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:56:38 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/09 21:56:39 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	ctd;

	ctd = 0;
	while (ctd <= 46340)
	{
		if ((ctd * ctd) == nb)
			return (ctd);
		ctd++;
	}
	return (0);
}

/*int main(){

	
	printf("result = %d", ft_sqrt(0));
	return 0;
}*/