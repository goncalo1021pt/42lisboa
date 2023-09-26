/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:34:48 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/10 14:21:25 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	ctd;

	ctd = 2;
	if (nb <= 1)
		return (0);
	while (ctd * ctd <= nb)
	{
		if (nb % ctd == 0)
			return (0);
		ctd++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	next;

	if (nb < 2)
		return (2);
	if (nb % 2 == 0)
		next = nb + 1; 
	else
		next = nb + 2; 
	if (ft_is_prime(next))
		return (next);
	return (ft_find_next_prime(next)); 
}

/*int main(){

	printf("result = %d", ft_find_next_prime(17));
	return 0;
}*/