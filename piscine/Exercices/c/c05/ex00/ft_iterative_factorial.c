/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:50:04 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/09 21:45:43 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	ctd;
	int	result;

	result = 1;
	ctd = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	while (ctd <= nb)
	{
		result *= ctd;
		ctd++;
	}
	return (result);
}

/*int main(){

	printf("result = %d", ft_iterative_factorial(5));
	return 0;
}*/