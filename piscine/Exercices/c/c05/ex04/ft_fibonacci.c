/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:54:46 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/09 21:55:50 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	int	result;

	result = 0;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	result += (ft_fibonacci(index - 2));
	result += (ft_fibonacci(index - 1));
	return (result);
}

/*int main(){

	printf("result = %d",  ft_fibonacci(7));
	return 0;
}*/
