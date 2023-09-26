/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 14:59:47 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/03 21:51:26 by gfontao-         ###   ########.fr       */
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	while (ctd < size)
	{
		ctd2 = ctd;
		while (ctd2 < size)
		{
			if (tab[ctd] > tab[ctd2])
			{
				swap(&tab[ctd], &tab[ctd2]);
			}
			ctd2++;
		}
		ctd++;
	}
}

/*int main(){
	int n[] = {0,8,7,6,5,4,3,2,9,1};
	int ctd=0;
	
	
	ft_sort_int_tab(n, 10);
	ctd = 0;
	while (ctd < 10)
	{
		printf("%d ",n[ctd]);
		ctd++;
	}
}*/