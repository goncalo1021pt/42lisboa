/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:17:09 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/05 09:33:23 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base, int total)
{
	int			bl;
	char		c;

	bl = ft_strlen(base);
	if ((nbr / bl) > 0)
	{
		total = ft_putnbr_base(nbr / bl, base, total);
		total = ft_putnbr_base(nbr % bl, base, total);
	}
	else
	{
		c = base[nbr];
		total += write(1, &c, 1);
	}
	return (total);
}

int	ft_putpt(unsigned long int nbr, char *base, int total)
{
	int			bl;
	char		c;

	bl = ft_strlen(base);
	if ((nbr / bl) > 0)
	{
		total = ft_putpt(nbr / bl, base, total);
		total = ft_putpt(nbr % bl, base, total);
	}
	else
	{
		c = base[nbr];
		total += write(1, &c, 1);
	}
	return (total);
}

int	ft_putnbr(int n, int total)
{
	char		c;

	if (n == -2147483648)
		total += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			total += write(1, "-", 1);
		}
		if ((n / 10) > 0)
		{
			total = ft_putnbr(n / 10, total);
			total = ft_putnbr(n % 10, total);
		}
		else
		{
			c = n + '0';
			total += write(1, &c, 1);
		}
	}
	return (total);
}

int	ft_putunbr(unsigned int n, int total)
{
	char		c;

	if ((n / 10) > 0)
	{
		total = ft_putunbr(n / 10, total);
		total = ft_putunbr(n % 10, total);
	}
	else
	{
		c = n + '0';
		total += write(1, &c, 1);
	}
	return (total);
}
