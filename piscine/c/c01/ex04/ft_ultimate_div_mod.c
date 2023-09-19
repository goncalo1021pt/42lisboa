/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:14:46 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/03 21:53:03 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp0;
	int	temp1;

	temp0 = *a / *b;
	temp1 = *a % *b;
	*a = temp0;
	*b = temp1;
}

/*int main(){
	int a=7,b=2;
	ft_ultimate_div_mod(&a,&b);
	printf("div = %d\nmod = %d",a,b);
}*/