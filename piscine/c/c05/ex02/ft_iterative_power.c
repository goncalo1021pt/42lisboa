/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:51:46 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/09 10:52:35 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	ctd;
	int	result;

	ctd = 1;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (ctd < power)
	{
		result *= nb;
		ctd++;
	}
	return (result);
}

/*int main(){

	printf("result = %d",  ft_iterative_power(2,4));
	return 0;
}*/