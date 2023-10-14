/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:17:09 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/13 12:24:35 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_put_any_base(unsigned long int nbr, char *base, int total)
{
	int		bl;
	char	c;

	bl = ft_strlen(base);
	if ((nbr / bl) > 0)
	{
		total = ft_put_any_base(nbr / bl, base, total);
		total = ft_put_any_base(nbr % bl, base, total);
	}
	else
	{
		c = base[nbr];
		total += write(1, &c, 1);
	}
	return (total);
}

int	int_aux(long int nbr)
{
	int	total;

	total = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		total += write(1, "-", 1);
	}
	total += ft_put_any_base(nbr, DEC_BASE, total);
	return (total);
}

int	is_char(const char *str, const char c)
{
	int	ctd;

	ctd = 0;
	while (str[ctd])
	{
		if (str[ctd] == c)
			return (1);
		ctd++;
	}
	return (0);
}

int	ptraux(unsigned long int ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		len += ft_putstr_fd("(nil)", 1);
	else
	{
		len += write(1, "0x", 2);
		len += ft_put_any_base(ptr, EX_LOW_BASE, 0);
	}
	return (len);
}

int	straux(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	else
		return (ft_putstr_fd(str, 1));
}