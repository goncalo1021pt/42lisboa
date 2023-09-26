/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:31:32 by gfontao-          #+#    #+#             */
/*   Updated: 2023/09/18 21:00:44 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
		ctd++;
	return (ctd);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->copy != 0)
	{
		write(1, par->str, ft_strlen(par->str));
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		write(1, par->copy, ft_strlen(par->copy));
		write(1, "\n", 1);
		par++;
	}
}
