/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:12:08 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/14 16:36:13 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *num, int n)
{
	int		ctd;
	int		low;

	ctd = 1;
	low = 1;
	while (ctd < n)
	{
		if (num[ctd - 1] >= num[ctd])
			low = 0;
		ctd++;
	}
	if (low)
	{
		ctd = 0;
		while (ctd < n)
			ft_putchar(num[ctd++] + 48);
		if (num[0] < (10 - n))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_combn(int n)
{
	int		ctd;
	int		num[9];

	ctd = 0;
	while (ctd < n)
		num[ctd++] = 0;
	while (num[0] <= (10 - n) && n >= 1 && n < 10)
	{
		print(num, n);
		num[n - 1]++;
		ctd = n - 1;
		while (ctd && n > 1)
		{
			if (num[ctd] > 9)
			{
				num[ctd - 1]++;
				num[ctd] = 0;
			}
			ctd--;
		}
	}
}

/*int	main()
{
	ft_print_combn(3);
}*/