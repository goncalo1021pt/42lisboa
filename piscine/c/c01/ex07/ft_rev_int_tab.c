/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:36:13 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/03 18:42:19 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	ctd;
	int	reverse;

	ctd = 0;
	reverse = size - 1;
	while (ctd < size / 2)
	{
		swap(&tab[ctd], &tab[reverse]);
		ctd++;
		reverse--;
	}
}
/*int main(){
	int n[] = {0,1,2,3,4,5,6,7,8};
	int ctd=0;
	
	
	ft_rev_int_tab(n, 9);
	ctd = 0;
	while (ctd < 9)
	{
		printf("%d ",n[ctd]);
		ctd++;
	}
}*/