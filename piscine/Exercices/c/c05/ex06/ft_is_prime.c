/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:17:54 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/12 13:27:44 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	ctd;

	ctd = 2;
	if (nb <= 1)
		return (0);
	while (ctd <= nb / 2)
	{
		if (nb % ctd == 0)
			return (0);
		ctd++;
	}
	return (1);
}

/*int main(){

	printf("result = %d", ft_is_prime(3));
	return 0;
}*/
