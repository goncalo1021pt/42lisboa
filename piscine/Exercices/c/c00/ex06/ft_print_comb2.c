/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:25:32 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/14 19:07:27 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		if ((nb / 10) > 0)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else 
		{
			c = nb + '0';
			write(1, &c, 1);
		}
	}
}

void	ft_print_comb2(void)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	while (ctd <= 99)
	{
		ctd2 = ctd + 1;
		while (ctd2 <= 99)
		{
			if (ctd < 10)
				write(1, "0", 1);
			ft_putnbr(ctd);
			write(1, " ", 1);
			if (ctd2 < 10)
				write(1, "0", 1);
			ft_putnbr(ctd2);
			if (!(ctd == 98 && ctd2 == 99))
				write(1, ", ", 2);
			ctd2++;
		}
		ctd++;
	}
}

/*int main()
{
    ft_print_comb2();
}*/
